import * as path from 'path';
import * as fs from 'fs';
import * as ESLintPlugin from 'eslint-webpack-plugin';
import {fileURLToPath} from 'url';

const copyResourcesToCpp = ()=>{
    const indexHtml = fs.readFileSync('./index.html',"utf8");
    const indexJs = fs.readFileSync('./out/index.js',"utf8");
    const cppSource =
`
#include <Arduino.h>

struct V_FILE
{
    String mime;
    String content;
};


const V_FILE static_index_html
(
    {
        String("text/html"),
        String(
            R"html(
            ${indexHtml}
            )html"
        )    
    }
);

const V_FILE static_index_js
(
    {
        String("text/javascript"),
        String(
            R"html(
            ${indexJs}
            )html"
        ) 
    }   
);
`;

    fs.writeFileSync('../src/static/static.h',cppSource,{encoding:'utf8'});
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
            minimize: false,
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



