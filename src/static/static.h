
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
            <!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, minimal-ui, initial-scale=1.0, maximum-scale=1.0, user-scalable=no, viewport-fit=cover" />
    <meta charset="UTF-8">
    <title>ESP32</title>
    <style>
        * {
            font-family: monospace;
            font-size: 10px;
        }
        body {
            background-color: #e7e7e7;
        }
        .frame_out {
            margin: 5px;
            position: relative;
            border: 1px solid grey;
            background-color: #d9d9d9;
            box-shadow: 5px 5px 1px #363636;
            padding: 6px;
        }
        .frame_title_wrap {
            border: 1px solid grey;
            position: absolute;
            left: 30px;
            top: 1px;
        }
        .frame_title {
            display: inline-block;
            padding: 2px;
            position: relative;
            color: black;
            background-color: white;
        }
        .frame_in_1 {
            border: 1px solid grey;
            padding: 1px;
            margin: 5px;
        }
        .frame_in_2 {
            border: 1px solid grey;
            padding: 15px 5px;
        }
        ul {
            margin: 10px 0;
            padding: 0;
        }
        li {
            margin-left: 20px;
            list-style-type: square;
            overflow: hidden;
            text-overflow: ellipsis;
            text-emphasis: #af0000;
        }
        .status_bar {
            padding: 5px;
            margin: 15px;
            box-shadow: 1px 1px 1px #363636;
        }
        .ok {
            background-color: #01a801;
            color: white;
        }
        .error {
            background-color: #af0000;
            color: #c5c500;
        }
        input {
            padding: 2px 5px;
            margin: 5px;
            display: inline-block;
            min-width: 500px;
        }
        button {
            margin: 2px 5px;
            padding: 5px;
            position: relative;
            box-shadow: 5px 5px 1px #363636;
        }
        button::before {
            content: '◀';
        }
        button::after {
            content: '▶';
        }
        button:active {
            left: 3px;
            top: 2px;
            box-shadow: 2px 3px 1px #363636;
        }
    </style>
</head>
<body>
<script src="./out/index.js"></script>
</body>
</html>

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
            !function(){"use strict";var e=function(t,n){return e=Object.setPrototypeOf||{__proto__:[]}instanceof Array&&function(e,t){e.__proto__=t}||function(e,t){for(var n in t)Object.prototype.hasOwnProperty.call(t,n)&&(e[n]=t[n])},e(t,n)};function t(t,n){if("function"!=typeof n&&null!==n)throw new TypeError("Class extends value "+String(n)+" is not a constructor or null");function r(){this.constructor=t}e(t,n),t.prototype=null===n?Object.create(n):(r.prototype=n.prototype,new r)}var n=function(){return n=Object.assign||function(e){for(var t,n=1,r=arguments.length;n<r;n++)for(var o in t=arguments[n])Object.prototype.hasOwnProperty.call(t,o)&&(e[o]=t[o]);return e},n.apply(this,arguments)};function r(e,t,n,r,o,i){function a(e){if(void 0!==e&&"function"!=typeof e)throw new TypeError("Function expected");return e}for(var c,s=r.kind,l="getter"===s?"get":"setter"===s?"set":"value",u=!t&&e?r.static?e:e.prototype:null,d=t||(u?Object.getOwnPropertyDescriptor(u,r.name):{}),p=!1,h=n.length-1;h>=0;h--){var f={};for(var m in r)f[m]="access"===m?{}:r[m];for(var m in r.access)f.access[m]=r.access[m];f.addInitializer=function(e){if(p)throw new TypeError("Cannot add initializers after decoration has completed");i.push(a(e||null))};var v=(0,n[h])("accessor"===s?{get:d.get,set:d.set}:d[l],f);if("accessor"===s){if(void 0===v)continue;if(null===v||"object"!=typeof v)throw new TypeError("Object expected");(c=a(v.get))&&(d.get=c),(c=a(v.set))&&(d.set=c),(c=a(v.init))&&o.unshift(c)}else(c=a(v))&&("field"===s?o.unshift(c):d[l]=c)}u&&Object.defineProperty(u,r.name,d),p=!0}function o(e,t,n){for(var r=arguments.length>2,o=0;o<t.length;o++)n=r?t[o].call(e,n):t[o].call(e);return r?n:void 0}function i(e,t,n,r){return new(n||(n=Promise))((function(o,i){function a(e){try{s(r.next(e))}catch(e){i(e)}}function c(e){try{s(r.throw(e))}catch(e){i(e)}}function s(e){var t;e.done?o(e.value):(t=e.value,t instanceof n?t:new n((function(e){e(t)}))).then(a,c)}s((r=r.apply(e,t||[])).next())}))}function a(e,t){var n,r,o,i,a={label:0,sent:function(){if(1&o[0])throw o[1];return o[1]},trys:[],ops:[]};return i={next:c(0),throw:c(1),return:c(2)},"function"==typeof Symbol&&(i[Symbol.iterator]=function(){return this}),i;function c(c){return function(s){return function(c){if(n)throw new TypeError("Generator is already executing.");for(;i&&(i=0,c[0]&&(a=0)),a;)try{if(n=1,r&&(o=2&c[0]?r.return:c[0]?r.throw||((o=r.return)&&o.call(r),0):r.next)&&!(o=o.call(r,c[1])).done)return o;switch(r=0,o&&(c=[2&c[0],o.value]),c[0]){case 0:case 1:o=c;break;case 4:return a.label++,{value:c[1],done:!1};case 5:a.label++,r=c[1],c=[0];continue;case 7:c=a.ops.pop(),a.trys.pop();continue;default:if(!((o=(o=a.trys).length>0&&o[o.length-1])||6!==c[0]&&2!==c[0])){a=0;continue}if(3===c[0]&&(!o||c[1]>o[0]&&c[1]<o[3])){a.label=c[1];break}if(6===c[0]&&a.label<o[1]){a.label=o[1],o=c;break}if(o&&a.label<o[2]){a.label=o[2],a.ops.push(c);break}o[2]&&a.ops.pop(),a.trys.pop();continue}c=t.call(e,a)}catch(e){c=[6,e],r=0}finally{n=o=0}if(5&c[0])throw c[1];return{value:c[0]?c[1]:void 0,done:!0}}([c,s])}}}Object.create,Object.create,"function"==typeof SuppressedError&&SuppressedError;var c,s=function(e,t,n){void 0===n&&(n=[]),this.props=e,this.tagName=t,this.children=n,this.index=0,this.loopIndex=void 0,this.type="virtualNode"},l=function(e){function n(t){var n=e.call(this,{children:void 0},void 0,void 0)||this;return n.text=t,n}return t(n,e),n}(s),u=function(e){function n(t,n){var r=e.call(this,t,void 0,void 0)||this;return r.comment=n,r}return t(n,e),n}(s),d=function(e){void 0===e&&(e=[]),this.children=e,this.tagName=void 0,this.type="virtualFragment"},p=function(e){return e.reduce((function(e,t){return Array.isArray(t)?(t.forEach((function(e,t){e.loopIndex=t})),e.concat(p(t))):e.concat(t)}),[])},h=function(e){var t;return null!==(t=e.trackBy)&&void 0!==t?t:e.__id},f=function(){function e(){}return e.renderComponent=function(e,t){e.props=t;var n=e.render(),r=new u(t,"cid:".concat(h(t)));return r.parentComponent=e,n.children.unshift(r),n},e.createElement=function(t,r){for(var o=[],i=2;i<arguments.length;i++)o[i-2]=arguments[i];null===r&&(r={});for(var a=[],c=0,u=p(o).map((function(e,t){return void 0!==(null==e?void 0:e.substr)||void 0!==(null==e?void 0:e.toFixed)?new l(String(e)):e})).filter((function(e){return!!e}));c<u.length;c++){var d=u[c];"virtualFragment"===d.type?a.push.apply(a,d.children):a.push(d)}var f=n(n({},r),{children:a});if(t.__VEngineTsxComponent){var m=h(r);if(e.componentInstances[m]){var v=e.componentInstances[m];return this.renderComponent(v,f)}return v=new t(f),e.componentInstances[m]=v,this.renderComponent(v,f)}return void 0!==t.call?t(f):new s(f,t,a)},e.destroyElement=function(t){var n,r=this;e.clearCachedInstance(null===(n=t.parentComponent)||void 0===n?void 0:n.props),t.children.forEach((function(e){return r.destroyElement(e)}))},e.clearCachedInstance=function(e){if(e){var t=h(e);delete this.componentInstances[t]}},e.createFragment=function(e){var t=e.children;return new d(t)},e.clean=function(){this.componentInstances={}},e.componentInstances={},e}(),m=function(e){return f.createElement(f.createFragment,null,f.createElement("div",{className:"frame_out",__id:19},f.createElement("div",{className:"frame_title_wrap",__id:20},f.createElement("div",{className:"frame_title",__id:21},e.title)),f.createElement("div",{className:"frame_in_1",__id:22},f.createElement("div",{className:"frame_in_2",__id:23},e.children))))};c||(c={});var v,y=function(e){function n(t){var n=e.call(this)||this;return n.tsxDOMRenderer=t,n.rendering=!1,c.ROOT&&f.clean(),c.ROOT=n,n}return t(n,e),n.prototype._triggerRendering=function(){this.rendering||(this.rendering=!0,void 0!==this.rootNativeElement&&(this.rootVirtualElement=this.tsxDOMRenderer.render(this,this.rootNativeElement)),this.rendering=!1)},n.prototype.mountTo=function(e){e.removeChildren(),this.rootNativeElement=e,this._triggerRendering(),this.onMounted()},n.prototype.destroy=function(){f.destroyElement(this.rootVirtualElement)},n}(function(){function e(){this.__shouldBeMounted=!0}return e.prototype.onMounted=function(){},e.prototype._triggerRendering=function(){c.ROOT._triggerRendering()},e.__VEngineTsxComponent=!0,e}()),g=function(){function e(e){this.elementCreator=e,this.toMount=[]}return e.prototype.render=function(e,t){var n=e.render(),r=[];"virtualFragment"===n.type?r.push.apply(r,n.children):r.push(n);var o=new s({},"root",r);this.reconcileChildren(o,this.oldVirtualDom,t),this.oldVirtualDom=o;for(var i=0,a=this.toMount;i<a.length;i++)a[i].onMounted();return this.toMount.length=0,o},e.prototype.removeNode=function(e,t){e.removeSelf(),f.destroyElement(t)},e.prototype.replaceNode=function(e,t,n,r){var o=this.elementCreator.createElementByTagName(n);return this.setGenericProps(o,n,r),r.replaceChild(e,o),f.destroyElement(t),o},e.prototype.updateNode=function(e,t,n){this.setGenericProps(e,t,n)},e.prototype.createNode=function(e,t){var n,r=this.elementCreator.createElementByTagName(e);return this.setGenericProps(r,e,t),t.appendChild(r),(null===(n=e.parentComponent)||void 0===n?void 0:n.__shouldBeMounted)&&(e.parentComponent.__shouldBeMounted=!1,this.toMount.push(e.parentComponent)),r},e.prototype.reconcile=function(e,t,n,r){var o,i,a=n;return void 0===e&&void 0!==t?void 0!==a&&this.removeNode(a,t):void 0!==e&&void 0!==t&&void 0!==a?e.index!==t.index||(null===(o=e.props)||void 0===o?void 0:o.__id)!==(null===(i=t.props)||void 0===i?void 0:i.__id)||e.loopIndex!==t.loopIndex||e.tagName!==t.tagName?a=this.replaceNode(a,t,e,r):this.updateNode(a,e,r):void 0===e||void 0!==t&&void 0!==a||(a=this.createNode(e,r)),void 0!==a&&this.reconcileChildren(e,t,a),a},e.prototype.reconcileChildren=function(e,t,n){for(var r,o,i,a,c,s,l=Math.max(null!==(o=null===(r=null==e?void 0:e.children)||void 0===r?void 0:r.length)&&void 0!==o?o:0,null!==(a=null===(i=null==t?void 0:t.children)||void 0===i?void 0:i.length)&&void 0!==a?a:0),u=[],d=0,p=n.getChildrenCount();d<p;++d)u.push(n.getChildAt(d));for(d=0;d<l;++d){var h=null===(c=null==e?void 0:e.children)||void 0===c?void 0:c[d],f=null===(s=null==t?void 0:t.children)||void 0===s?void 0:s[d];this.reconcile(h,f,u[d],n)}},e.prototype.setGenericProps=function(e,t,n){var r;void 0!==(null===(r=null==t?void 0:t.props)||void 0===r?void 0:r.ref)&&t.props.ref(e),this.elementCreator.setProps(e,t,n)},e}(),E=function(){function e(e){this.htmlElement=e,this.attributes={},this._childrenCache=[]}return e.prototype.appendChild=function(e){this.htmlElement.styleSheet&&!this.htmlElement.sheet?this.htmlElement.styleSheet.cssText=e.htmlElement.data:this.htmlElement.appendChild(e.htmlElement)},e.prototype.removeSelf=function(){this.htmlElement.parentNode.removeChild(this.htmlElement),O.getInstance().onElementRemoved(this.htmlElement)},e.prototype.replaceChild=function(e,t){O.getInstance().onElementRemoved(e.htmlElement),this.htmlElement.replaceChild(t.htmlElement,e.htmlElement)},e.prototype.getChildAt=function(e){if(3!==this.htmlElement.nodeType){var t=this.htmlElement.childNodes[e];return _(t)}},e.prototype._getChildren=function(){this._childrenCache.length=0;for(var e=0,t=this.htmlElement.childNodes.length;e<t;++e){var n=this.htmlElement.childNodes[e];this._childrenCache.push(_(n))}return this._childrenCache},e.prototype.getChildrenCount=function(){return 3===this.htmlElement.nodeType?0:this.htmlElement.childNodes.length},e.prototype.getParentNode=function(){return _(this.htmlElement.parentElement)},e.prototype.removeChildren=function(){3===this.htmlElement.nodeType&&(this.htmlElement.data=""),this.htmlElement.innerHTML=""},e}(),_=function(e){return O.getInstance().getWrapByElement(e)},b=["value","checked","selected","focus","disabled","readonly"],w=["children","__id"],C=["svg","g","rect","path","circle","line"],O=function(){function e(){this.elements=[],this.wrappers=[]}return e.getInstance=function(){return e.instance},e.prototype.onElementCreated=function(e){this.elements.push(e)},e.prototype.onElementRemoved=function(e){var t=this.elements.indexOf(e);this.elements.splice(t,1),this.wrappers.splice(t,1)},e.prototype.getWrapByElement=function(e){var t=this.elements.indexOf(e);return this.wrappers[t]=this.wrappers[t]||new E(e),this.wrappers[t]},e.instance=new e,e}(),x=function(e){function n(){return e.call(this)||this}return t(n,e),n.prototype.createElementByTagName=function(e){var t;return t=e instanceof l?document.createTextNode(e.text):e instanceof u?document.createComment(e.comment):C.indexOf(e.tagName)>-1?document.createElementNS("http://www.w3.org/2000/svg",e.tagName):document.createElement(e.tagName),O.getInstance().onElementCreated(t),new E(t)},n.prototype.setProps=function(e,t,n){var r=t.props,o=e.htmlElement;if(3===o.nodeType){var i=t;i.text!==e.attributes.text&&(e.attributes.text=i.text,o.data=i.text)}else for(var a=o,c=function(n){if(0===n.indexOf("on"))a[n]=r[n];else if(e.attributes[n]!==r[n]){e.attributes[n]=r[n];var i=n;if(w.indexOf(i)>-1)return"continue";if("style"===i){var c=r[n];if(null==c?void 0:c.substr)a.setAttribute("style",c);else{var s=t.props.style;Object.keys(c).forEach((function(e){return a.style[e]=c[e]})),Object.keys(s).forEach((function(e){void 0===c[e]&&(a.style[e]=void 0)}))}return"continue"}if("htmlFor"===n)i="for";else if("className"===n)i="class";else if("ref"===n)return t.props.ref(o),"continue";if(b.indexOf(n)>-1)a[n]=r[n];else null==r[n]?a.removeAttribute(i):a.setAttribute(i,r[n])}},s=0,l=Object.keys(r);s<l.length;s++)c(l[s])},n}((function(){})),N=function(e){function n(){return e.call(this,new x)||this}return t(n,e),n}(g),T=function(e){function n(){return e.call(this,new N)||this}return t(n,e),n}(y),j=function(){for(var e=[],t=0;t<arguments.length;t++)e[t]=arguments[t]};!function(e){e.request=function(e){var t,n=!1;e.method=e.method||"get",e.data&&"get"===e.method&&(e.url+="?"+function(e){if(null==e)return"";if(e instanceof FormData)return e;var t=[];return"string"==typeof e||"number"==typeof e?e.toString():(Object.keys(e).forEach((function(n){t.push([n,encodeURIComponent(e[n])])})),t.map((function(e){return[e[0]+"="+e[1]]})).join("&"))}(e.data));var r,o=new XMLHttpRequest,i=j,a=j;return"Promise"in window&&(r=new Promise((function(e,t){i=e,a=t}))),o.onreadystatechange=function(){if(4===o.readyState){if(o.status>=200&&o.status<=299||0===o.status){var r=o.responseText;if((o.getResponseHeader("Content-Type")||"").toLowerCase().indexOf("json")>-1&&r&&void 0!==r.substr)try{r=JSON.parse(r)}catch(e){console.log(e)}e.success&&e.success(r),i(r)}else{var c=void 0;try{c=JSON.parse(o.response)}catch(e){c=o.response}e.error&&e.error({status:o.status,error:o.statusText,response:c}),a(c)}clearTimeout(t),n=!0}},o.open(e.method,e.url,!0),e.setup&&e.setup(o),e.requestType?"multipart/form-data"!==e.requestType&&o.setRequestHeader("Content-Type",e.requestType):o.setRequestHeader("Content-Type","application/x-www-form-urlencoded"),void 0!==e.headers&&Object.keys(e.headers).forEach((function(t){o.setRequestHeader(t,e.headers[t])})),"application/json"===e.requestType&&(e.data=e.data&&JSON.stringify(e.data)),o.send(e.data),e.timeout&&(t=setTimeout((function(){n||(o.abort(),e.ontimeout&&e.ontimeout(),a("timeout"))}),e.timeout)),r},e.get=function(t,n,r,o,i){return e.request({method:"get",url:t,data:n,success:r,error:o,setup:i})},e.post=function(t,n,r,o,i){return e.request({method:"post",url:t,data:n,requestType:"application/json",success:r,error:o,setup:i})},e.postMultiPart=function(t,n,r,o,i,a){var c=new FormData;return Object.keys(r).forEach((function(e){c.append(e,r[e])})),c.append("file",n),c.append("fileName",n.name),e.request({method:"post",url:t,data:c,requestType:"multipart/form-data",success:o,error:i,setup:a})}}(v||(v={}));var R,I,S,P,M,k,q,F,B=(q=[],F=[],R=function(e){function n(){var t=null!==e&&e.apply(this,arguments)||this;return t.cnt=(o(t,q),o(t,F,"0")),t}return t(n,e),n.prototype.inc=function(e){return i(this,void 0,void 0,(function(){var e;return a(this,(function(t){switch(t.label){case 0:return e=+this.cnt,e++,[4,v.post("/preferences/cnt",{cnt:"".concat(e)})];case 1:return t.sent(),this.cnt="".concat(e),[2]}}))}))},n.prototype.onMounted=function(){var t;return i(this,void 0,void 0,(function(){var n;return a(this,(function(r){switch(r.label){case 0:return e.prototype.onMounted.call(this),n=this,[4,v.get("/preferences/cnt")];case 1:return n.cnt=null!==(t=r.sent().cnt)&&void 0!==t?t:"0",[2]}}))}))},n.prototype.render=function(){return f.createElement(f.createFragment,null,f.createElement(m,{title:"Привіт",__id:16},"Ця html - сторінка працює на мікроконтролері ESP32.",f.createElement("div",{__id:17},this.cnt),f.createElement("button",{onclick:this.inc,__id:18},"click")))},n}(k=T),I=[function(e,t){t.addInitializer((function(){var e=void 0;Object.defineProperty(this,t.name,{get:function(){return e},set:function(t){e=t,c.ROOT._triggerRendering()}})}))}],S=[function(e,t){t.addInitializer((function(){var n=this;this[t.name]=function(){for(var t=[],r=0;r<arguments.length;r++)t[r]=arguments[r];var o=e.apply(n,t);return c.ROOT._triggerRendering(),o instanceof Promise&&o.then((function(){c.ROOT._triggerRendering()})),o}}))}],r(R,null,S,{kind:"method",name:"inc",static:!1,private:!1,access:{has:function(e){return"inc"in e},get:function(e){return e.inc}},metadata:M="function"==typeof Symbol&&Symbol.metadata?Object.create(null!==(P=k[Symbol.metadata])&&void 0!==P?P:null):void 0},null,q),r(null,null,I,{kind:"field",name:"cnt",static:!1,private:!1,access:{has:function(e){return"cnt"in e},get:function(e){return e.cnt},set:function(e,t){e.cnt=t}},metadata:M},F,q),M&&Object.defineProperty(R,Symbol.metadata,{enumerable:!0,configurable:!0,writable:!0,value:M}),R),A=document.createElement("div");A.id="root",document.body.appendChild(A),(new B).mountTo(new E(A))}();
            )html"
        ) 
    }   
);
