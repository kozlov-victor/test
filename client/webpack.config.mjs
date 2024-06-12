import * as path from 'path';
import * as fs from 'fs';
import * as ESLintPlugin from 'eslint-webpack-plugin';
import {fileURLToPath} from 'url';

const bufferAsCppCode = (buff)=>{
    const size = Buffer.byteLength(buff);
    const lines = [`\n    {`];
    let cnt = 0;
    for (const x of buff) {
        lines.push(
            '0x'+x.toString(16).padStart(2, '0') + (cnt<size-1?', ':'')
        );
        cnt++;
        if (cnt===500) {
            cnt = 0;
            lines.push('\n    ');
        }
    }
    lines.push('}');
    return lines.join('');
}

const copyResourcesToCpp = ()=>{
    const assetsBin = [];
    assetsBin.push({
        buff: fs.readFileSync('./index.html'),
        name: 'assets_index_html',
        mime: "text/html",
    });
    assetsBin.push({
        buff: fs.readFileSync('./out/index.js'),
        name: 'assets_index_js',
        mime: "application/js",
    });

    fs.readdirSync('./src/assets').forEach(f => {
        const buff = fs.readFileSync(`./src/assets/${f}`);
        assetsBin.push({
            buff,
            name:'assets_'+f.replaceAll('.','_'),
            mime: "image/png",
        });
    });

    const cppSource =
`
#include <Arduino.h>
#include <stdint.h>  // Додаємо цей заголовок для типів uint8_t, uint16_t тощо

struct V_FILE
{
    String mime;
    const uint8_t* buff;
    size_t size;
};

${assetsBin.map(f=>{
    return `
    
const uint8_t __${f.name}__[] PROGMEM = ${bufferAsCppCode(f.buff)};    
    
const V_FILE ${f.name} = 
{
    "${f.mime}",
    __${f.name}__,
    ${Buffer.byteLength(f.buff)}
};
    `;
}).join('\n')}
`;

    fs.writeFileSync('../src/server/static/static.h',cppSource,{encoding:'utf8'});
}

class WebpackDonePlugin{
    apply(compiler){
        compiler.hooks.done.tap('compilation',  (stats)=> {
            setTimeout(()=>{
                if (stats.compilation.errors && stats.compilation.errors.length) {
                    console.error('compiled with errors');
                } else {
                    console.log('compiled');
                    copyResourcesToCpp();
                }
            },10);

        });

    }
}

export default async (env = {})=>{

    const entry = {};
    const output = {};

    entry['index'] = './src/index.ts';
    output.path = path.resolve('./out');

    output.filename = '[name].js';
    output.chunkFilename = "[name].chunk.js";

    const __dirname = path.dirname(fileURLToPath(import.meta.url));

    const config = {
        entry,
        output,
        target: ['web', 'es5'],
        mode: 'production', //debug ? 'development' : 'production',
        //devtool: 'inline-source-map',
        resolveLoader: {
            modules: ['node_modules', path.resolve(__dirname, 'node_tools/loaders')]
        },
        watchOptions: {
            aggregateTimeout: 2000,
            ignored: ['**/out/', '/node_modules/'],
        },
        performance: {
            maxEntrypointSize: 1024000,
            maxAssetSize: 1024000
        },
        module: {
            rules: [
                {
                    test: /\.(png|jpe?g)$/,
                    use: [
                        {loader: 'base64/base64-loader',options: {}}
                    ]
                },
                {
                    test: /\.tsx$/,
                    enforce: 'pre',
                    use: [
                        {
                            loader: "ts-engine-precompiler/tsx-precompiler"
                        },
                    ]
                },
                {
                    test: /\.tsx?$/,
                    use: [
                        {
                            loader: "ts-loader",options: {},
                        },
                    ]
                },
            ]
        },
        resolve: {
            extensions: ['.ts','.tsx','.js'],
            modules: [
                path.resolve(__dirname, 'node_modules'),
            ],
            alias: {
                '@engine': path.resolve(__dirname, 'engine'),
            },
        },
        optimization: {
            minimize: true,
            emitOnErrors: false,
        },
    };

    config.plugins = [
        new ESLintPlugin.default({
            context: '../',
            emitError: true,
            emitWarning: true,
            failOnError: true,
            extensions: ["ts", "tsx"],
        }),
        new WebpackDonePlugin()
    ];

    return config;
}



