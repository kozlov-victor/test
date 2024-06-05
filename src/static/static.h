
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
            /******/ (function() { // webpackBootstrap
/******/ 	"use strict";
var __webpack_exports__ = {};

;// CONCATENATED MODULE: ./node_modules/tslib/tslib.es6.mjs
/******************************************************************************
Copyright (c) Microsoft Corporation.

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
PERFORMANCE OF THIS SOFTWARE.
***************************************************************************** */
/* global Reflect, Promise, SuppressedError, Symbol */

var extendStatics = function(d, b) {
  extendStatics = Object.setPrototypeOf ||
      ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
      function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
  return extendStatics(d, b);
};

function __extends(d, b) {
  if (typeof b !== "function" && b !== null)
      throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
  extendStatics(d, b);
  function __() { this.constructor = d; }
  d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
}

var __assign = function() {
  __assign = Object.assign || function __assign(t) {
      for (var s, i = 1, n = arguments.length; i < n; i++) {
          s = arguments[i];
          for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p)) t[p] = s[p];
      }
      return t;
  }
  return __assign.apply(this, arguments);
}

function __rest(s, e) {
  var t = {};
  for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p) && e.indexOf(p) < 0)
      t[p] = s[p];
  if (s != null && typeof Object.getOwnPropertySymbols === "function")
      for (var i = 0, p = Object.getOwnPropertySymbols(s); i < p.length; i++) {
          if (e.indexOf(p[i]) < 0 && Object.prototype.propertyIsEnumerable.call(s, p[i]))
              t[p[i]] = s[p[i]];
      }
  return t;
}

function __decorate(decorators, target, key, desc) {
  var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
  if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
  else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
  return c > 3 && r && Object.defineProperty(target, key, r), r;
}

function __param(paramIndex, decorator) {
  return function (target, key) { decorator(target, key, paramIndex); }
}

function __esDecorate(ctor, descriptorIn, decorators, contextIn, initializers, extraInitializers) {
  function accept(f) { if (f !== void 0 && typeof f !== "function") throw new TypeError("Function expected"); return f; }
  var kind = contextIn.kind, key = kind === "getter" ? "get" : kind === "setter" ? "set" : "value";
  var target = !descriptorIn && ctor ? contextIn["static"] ? ctor : ctor.prototype : null;
  var descriptor = descriptorIn || (target ? Object.getOwnPropertyDescriptor(target, contextIn.name) : {});
  var _, done = false;
  for (var i = decorators.length - 1; i >= 0; i--) {
      var context = {};
      for (var p in contextIn) context[p] = p === "access" ? {} : contextIn[p];
      for (var p in contextIn.access) context.access[p] = contextIn.access[p];
      context.addInitializer = function (f) { if (done) throw new TypeError("Cannot add initializers after decoration has completed"); extraInitializers.push(accept(f || null)); };
      var result = (0, decorators[i])(kind === "accessor" ? { get: descriptor.get, set: descriptor.set } : descriptor[key], context);
      if (kind === "accessor") {
          if (result === void 0) continue;
          if (result === null || typeof result !== "object") throw new TypeError("Object expected");
          if (_ = accept(result.get)) descriptor.get = _;
          if (_ = accept(result.set)) descriptor.set = _;
          if (_ = accept(result.init)) initializers.unshift(_);
      }
      else if (_ = accept(result)) {
          if (kind === "field") initializers.unshift(_);
          else descriptor[key] = _;
      }
  }
  if (target) Object.defineProperty(target, contextIn.name, descriptor);
  done = true;
};

function __runInitializers(thisArg, initializers, value) {
  var useValue = arguments.length > 2;
  for (var i = 0; i < initializers.length; i++) {
      value = useValue ? initializers[i].call(thisArg, value) : initializers[i].call(thisArg);
  }
  return useValue ? value : void 0;
};

function __propKey(x) {
  return typeof x === "symbol" ? x : "".concat(x);
};

function __setFunctionName(f, name, prefix) {
  if (typeof name === "symbol") name = name.description ? "[".concat(name.description, "]") : "";
  return Object.defineProperty(f, "name", { configurable: true, value: prefix ? "".concat(prefix, " ", name) : name });
};

function __metadata(metadataKey, metadataValue) {
  if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(metadataKey, metadataValue);
}

function __awaiter(thisArg, _arguments, P, generator) {
  function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
  return new (P || (P = Promise))(function (resolve, reject) {
      function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
      function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
      function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
      step((generator = generator.apply(thisArg, _arguments || [])).next());
  });
}

function __generator(thisArg, body) {
  var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
  return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
  function verb(n) { return function (v) { return step([n, v]); }; }
  function step(op) {
      if (f) throw new TypeError("Generator is already executing.");
      while (g && (g = 0, op[0] && (_ = 0)), _) try {
          if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
          if (y = 0, t) op = [op[0] & 2, t.value];
          switch (op[0]) {
              case 0: case 1: t = op; break;
              case 4: _.label++; return { value: op[1], done: false };
              case 5: _.label++; y = op[1]; op = [0]; continue;
              case 7: op = _.ops.pop(); _.trys.pop(); continue;
              default:
                  if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                  if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                  if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                  if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                  if (t[2]) _.ops.pop();
                  _.trys.pop(); continue;
          }
          op = body.call(thisArg, _);
      } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
      if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
  }
}

var __createBinding = Object.create ? (function(o, m, k, k2) {
  if (k2 === undefined) k2 = k;
  var desc = Object.getOwnPropertyDescriptor(m, k);
  if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
  }
  Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
  if (k2 === undefined) k2 = k;
  o[k2] = m[k];
});

function __exportStar(m, o) {
  for (var p in m) if (p !== "default" && !Object.prototype.hasOwnProperty.call(o, p)) __createBinding(o, m, p);
}

function __values(o) {
  var s = typeof Symbol === "function" && Symbol.iterator, m = s && o[s], i = 0;
  if (m) return m.call(o);
  if (o && typeof o.length === "number") return {
      next: function () {
          if (o && i >= o.length) o = void 0;
          return { value: o && o[i++], done: !o };
      }
  };
  throw new TypeError(s ? "Object is not iterable." : "Symbol.iterator is not defined.");
}

function __read(o, n) {
  var m = typeof Symbol === "function" && o[Symbol.iterator];
  if (!m) return o;
  var i = m.call(o), r, ar = [], e;
  try {
      while ((n === void 0 || n-- > 0) && !(r = i.next()).done) ar.push(r.value);
  }
  catch (error) { e = { error: error }; }
  finally {
      try {
          if (r && !r.done && (m = i["return"])) m.call(i);
      }
      finally { if (e) throw e.error; }
  }
  return ar;
}

/** @deprecated */
function __spread() {
  for (var ar = [], i = 0; i < arguments.length; i++)
      ar = ar.concat(__read(arguments[i]));
  return ar;
}

/** @deprecated */
function __spreadArrays() {
  for (var s = 0, i = 0, il = arguments.length; i < il; i++) s += arguments[i].length;
  for (var r = Array(s), k = 0, i = 0; i < il; i++)
      for (var a = arguments[i], j = 0, jl = a.length; j < jl; j++, k++)
          r[k] = a[j];
  return r;
}

function __spreadArray(to, from, pack) {
  if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
      if (ar || !(i in from)) {
          if (!ar) ar = Array.prototype.slice.call(from, 0, i);
          ar[i] = from[i];
      }
  }
  return to.concat(ar || Array.prototype.slice.call(from));
}

function __await(v) {
  return this instanceof __await ? (this.v = v, this) : new __await(v);
}

function __asyncGenerator(thisArg, _arguments, generator) {
  if (!Symbol.asyncIterator) throw new TypeError("Symbol.asyncIterator is not defined.");
  var g = generator.apply(thisArg, _arguments || []), i, q = [];
  return i = {}, verb("next"), verb("throw"), verb("return"), i[Symbol.asyncIterator] = function () { return this; }, i;
  function verb(n) { if (g[n]) i[n] = function (v) { return new Promise(function (a, b) { q.push([n, v, a, b]) > 1 || resume(n, v); }); }; }
  function resume(n, v) { try { step(g[n](v)); } catch (e) { settle(q[0][3], e); } }
  function step(r) { r.value instanceof __await ? Promise.resolve(r.value.v).then(fulfill, reject) : settle(q[0][2], r); }
  function fulfill(value) { resume("next", value); }
  function reject(value) { resume("throw", value); }
  function settle(f, v) { if (f(v), q.shift(), q.length) resume(q[0][0], q[0][1]); }
}

function __asyncDelegator(o) {
  var i, p;
  return i = {}, verb("next"), verb("throw", function (e) { throw e; }), verb("return"), i[Symbol.iterator] = function () { return this; }, i;
  function verb(n, f) { i[n] = o[n] ? function (v) { return (p = !p) ? { value: __await(o[n](v)), done: false } : f ? f(v) : v; } : f; }
}

function __asyncValues(o) {
  if (!Symbol.asyncIterator) throw new TypeError("Symbol.asyncIterator is not defined.");
  var m = o[Symbol.asyncIterator], i;
  return m ? m.call(o) : (o = typeof __values === "function" ? __values(o) : o[Symbol.iterator](), i = {}, verb("next"), verb("throw"), verb("return"), i[Symbol.asyncIterator] = function () { return this; }, i);
  function verb(n) { i[n] = o[n] && function (v) { return new Promise(function (resolve, reject) { v = o[n](v), settle(resolve, reject, v.done, v.value); }); }; }
  function settle(resolve, reject, d, v) { Promise.resolve(v).then(function(v) { resolve({ value: v, done: d }); }, reject); }
}

function __makeTemplateObject(cooked, raw) {
  if (Object.defineProperty) { Object.defineProperty(cooked, "raw", { value: raw }); } else { cooked.raw = raw; }
  return cooked;
};

var __setModuleDefault = Object.create ? (function(o, v) {
  Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
  o["default"] = v;
};

function __importStar(mod) {
  if (mod && mod.__esModule) return mod;
  var result = {};
  if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
  __setModuleDefault(result, mod);
  return result;
}

function __importDefault(mod) {
  return (mod && mod.__esModule) ? mod : { default: mod };
}

function __classPrivateFieldGet(receiver, state, kind, f) {
  if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a getter");
  if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot read private member from an object whose class did not declare it");
  return kind === "m" ? f : kind === "a" ? f.call(receiver) : f ? f.value : state.get(receiver);
}

function __classPrivateFieldSet(receiver, state, value, kind, f) {
  if (kind === "m") throw new TypeError("Private method is not writable");
  if (kind === "a" && !f) throw new TypeError("Private accessor was defined without a setter");
  if (typeof state === "function" ? receiver !== state || !f : !state.has(receiver)) throw new TypeError("Cannot write private member to an object whose class did not declare it");
  return (kind === "a" ? f.call(receiver, value) : f ? f.value = value : state.set(receiver, value)), value;
}

function __classPrivateFieldIn(state, receiver) {
  if (receiver === null || (typeof receiver !== "object" && typeof receiver !== "function")) throw new TypeError("Cannot use 'in' operator on non-object");
  return typeof state === "function" ? receiver === state : state.has(receiver);
}

function __addDisposableResource(env, value, async) {
  if (value !== null && value !== void 0) {
    if (typeof value !== "object" && typeof value !== "function") throw new TypeError("Object expected.");
    var dispose;
    if (async) {
        if (!Symbol.asyncDispose) throw new TypeError("Symbol.asyncDispose is not defined.");
        dispose = value[Symbol.asyncDispose];
    }
    if (dispose === void 0) {
        if (!Symbol.dispose) throw new TypeError("Symbol.dispose is not defined.");
        dispose = value[Symbol.dispose];
    }
    if (typeof dispose !== "function") throw new TypeError("Object not disposable.");
    env.stack.push({ value: value, dispose: dispose, async: async });
  }
  else if (async) {
    env.stack.push({ async: true });
  }
  return value;
}

var _SuppressedError = typeof SuppressedError === "function" ? SuppressedError : function (error, suppressed, message) {
  var e = new Error(message);
  return e.name = "SuppressedError", e.error = error, e.suppressed = suppressed, e;
};

function __disposeResources(env) {
  function fail(e) {
    env.error = env.hasError ? new _SuppressedError(e, env.error, "An error was suppressed during disposal.") : e;
    env.hasError = true;
  }
  function next() {
    while (env.stack.length) {
      var rec = env.stack.pop();
      try {
        var result = rec.dispose && rec.dispose.call(rec.value);
        if (rec.async) return Promise.resolve(result).then(next, function(e) { fail(e); return next(); });
      }
      catch (e) {
          fail(e);
      }
    }
    if (env.hasError) throw env.error;
  }
  return next();
}

/* harmony default export */ var tslib_es6 = ({
  __extends,
  __assign,
  __rest,
  __decorate,
  __param,
  __metadata,
  __awaiter,
  __generator,
  __createBinding,
  __exportStar,
  __values,
  __read,
  __spread,
  __spreadArrays,
  __spreadArray,
  __await,
  __asyncGenerator,
  __asyncDelegator,
  __asyncValues,
  __makeTemplateObject,
  __importStar,
  __importDefault,
  __classPrivateFieldGet,
  __classPrivateFieldSet,
  __classPrivateFieldIn,
  __addDisposableResource,
  __disposeResources,
});

;// CONCATENATED MODULE: ./engine/renderable/tsx/_genetic/virtualNode.ts

var VirtualNode = (function () {
    function VirtualNode(props, tagName, children) {
        if (children === void 0) { children = []; }
        this.props = props;
        this.tagName = tagName;
        this.children = children;
        this.index = 0;
        this.loopIndex = undefined;
        this.type = 'virtualNode';
    }
    return VirtualNode;
}());

var VirtualTextNode = (function (_super) {
    __extends(VirtualTextNode, _super);
    function VirtualTextNode(text) {
        var _this = _super.call(this, { children: undefined }, undefined, undefined) || this;
        _this.text = text;
        return _this;
    }
    return VirtualTextNode;
}(VirtualNode));

var VirtualCommentNode = (function (_super) {
    __extends(VirtualCommentNode, _super);
    function VirtualCommentNode(props, comment) {
        var _this = _super.call(this, props, undefined, undefined) || this;
        _this.comment = comment;
        return _this;
    }
    return VirtualCommentNode;
}(VirtualNode));


;// CONCATENATED MODULE: ./engine/renderable/tsx/_genetic/virtualFragment.ts
var VirtualFragment = (function () {
    function VirtualFragment(children) {
        if (children === void 0) { children = []; }
        this.children = children;
        this.tagName = undefined;
        this.type = 'virtualFragment';
    }
    return VirtualFragment;
}());


;// CONCATENATED MODULE: ./engine/renderable/tsx/_genetic/vEngineTsxFactory.h.ts



var flattenDeep = function (arr) {
    var res = arr.reduce(function (acc, val) {
        if (Array.isArray(val)) {
            val.forEach(function (v, i) {
                v.loopIndex = i;
            });
            return acc.concat(flattenDeep(val));
        }
        else
            return acc.concat(val);
    }, []);
    return res;
};
var getComponentUuid = function (props) {
    var _a;
    return (_a = props.trackBy) !== null && _a !== void 0 ? _a : props.__id;
};
var VEngineTsxFactory = (function () {
    function VEngineTsxFactory() {
    }
    VEngineTsxFactory.renderComponent = function (instance, props) {
        instance.props = props;
        var node = instance.render();
        var commentNode = new VirtualCommentNode(props, "cid:".concat(getComponentUuid(props)));
        commentNode.parentComponent = instance;
        node.children.unshift(commentNode);
        return node;
    };
    VEngineTsxFactory.createElement = function (item, props) {
        var children = [];
        for (var _i = 2; _i < arguments.length; _i++) {
            children[_i - 2] = arguments[_i];
        }
        if (props === null)
            props = {};
        var flattenedChildren = flattenDeep(children).
            map(function (it, i) {
            if ((it === null || it === void 0 ? void 0 : it.substr) !== undefined || (it === null || it === void 0 ? void 0 : it.toFixed) !== undefined) {
                return new VirtualTextNode(String(it));
            }
            else
                return it;
        }).
            filter(function (it) { return !!it; });
        var flattenedChildrenNoFragments = [];
        for (var _a = 0, flattenedChildren_1 = flattenedChildren; _a < flattenedChildren_1.length; _a++) {
            var node = flattenedChildren_1[_a];
            if (node.type === 'virtualFragment') {
                flattenedChildrenNoFragments.push.apply(flattenedChildrenNoFragments, node.children);
            }
            else
                flattenedChildrenNoFragments.push(node);
        }
        var propsWithChildren = __assign(__assign({}, props), { children: flattenedChildrenNoFragments });
        if (item.__VEngineTsxComponent) {
            var uuid = getComponentUuid(props);
            if (VEngineTsxFactory.componentInstances[uuid]) {
                var instance = VEngineTsxFactory.componentInstances[uuid];
                return this.renderComponent(instance, propsWithChildren);
            }
            else {
                var instance = new item(propsWithChildren);
                VEngineTsxFactory.componentInstances[uuid] = instance;
                return this.renderComponent(instance, propsWithChildren);
            }
        }
        else if (item.call !== undefined) {
            return item(propsWithChildren);
        }
        else {
            var tagName = item;
            return new VirtualNode(propsWithChildren, tagName, flattenedChildrenNoFragments);
        }
    };
    VEngineTsxFactory.destroyElement = function (el) {
        var _this = this;
        var _a;
        VEngineTsxFactory.clearCachedInstance((_a = el.parentComponent) === null || _a === void 0 ? void 0 : _a.props);
        el.children.forEach(function (it) { return _this.destroyElement(it); });
    };
    VEngineTsxFactory.clearCachedInstance = function (props) {
        if (!props)
            return;
        var uuid = getComponentUuid(props);
        delete this.componentInstances[uuid];
    };
    VEngineTsxFactory.createFragment = function (_a) {
        var children = _a.children;
        return new VirtualFragment(children);
    };
    VEngineTsxFactory.clean = function () {
        this.componentInstances = {};
    };
    VEngineTsxFactory.componentInstances = {};
    return VEngineTsxFactory;
}());


;// CONCATENATED MODULE: ./src/components/frame.tsx

var Frame = function (props) {
    return (VEngineTsxFactory.createElement(VEngineTsxFactory.createFragment, null,
        VEngineTsxFactory.createElement("div", { className: 'frame_out', __id: 1 },
            VEngineTsxFactory.createElement("div", { className: 'frame_title_wrap', __id: 2 },
                VEngineTsxFactory.createElement("div", { className: 'frame_title', __id: 3 }, props.title)),
            VEngineTsxFactory.createElement("div", { className: 'frame_in_1', __id: 4 },
                VEngineTsxFactory.createElement("div", { className: 'frame_in_2', __id: 5 }, props.children)))));
};

;// CONCATENATED MODULE: ./engine/renderable/tsx/_genetic/vEngineTsxRootHolder.ts
var VEngineTsxRootHolder;
(function (VEngineTsxRootHolder) {
})(VEngineTsxRootHolder || (VEngineTsxRootHolder = {}));

;// CONCATENATED MODULE: ./engine/renderable/tsx/decorator/reactive.ts

var Reactive = {
    Method: function () {
        return function (originalMethod, context) {
            context.addInitializer(function () {
                var _this = this;
                this[context.name] = (function () {
                    var args = [];
                    for (var _i = 0; _i < arguments.length; _i++) {
                        args[_i] = arguments[_i];
                    }
                    var result = originalMethod.apply(_this, args);
                    VEngineTsxRootHolder.ROOT._triggerRendering();
                    if (result instanceof Promise) {
                        result.then(function () {
                            VEngineTsxRootHolder.ROOT._triggerRendering();
                        });
                    }
                    return result;
                });
            });
        };
    },
    Property: function () {
        return function (originalProperty, context) {
            context.addInitializer(function () {
                var _val = undefined;
                Object.defineProperty(this, context.name, {
                    get: function () {
                        return _val;
                    },
                    set: function (val) {
                        _val = val;
                        VEngineTsxRootHolder.ROOT._triggerRendering();
                    }
                });
            });
        };
    },
    Function: function (fn) {
        return function () {
            var args = [];
            for (var _i = 0; _i < arguments.length; _i++) {
                args[_i] = arguments[_i];
            }
            var res = fn.apply(void 0, args);
            VEngineTsxRootHolder.ROOT._triggerRendering();
            if (res instanceof Promise) {
                res.then(function () {
                    VEngineTsxRootHolder.ROOT._triggerRendering();
                });
            }
            return res;
        };
    }
};

;// CONCATENATED MODULE: ./engine/renderable/tsx/base/baseTsxComponent.ts

var BaseTsxComponent = (function () {
    function BaseTsxComponent() {
        this.__shouldBeMounted = true;
    }
    BaseTsxComponent.prototype.onMounted = function () { };
    BaseTsxComponent.prototype._triggerRendering = function () {
        VEngineTsxRootHolder.ROOT._triggerRendering();
    };
    BaseTsxComponent.__VEngineTsxComponent = true;
    return BaseTsxComponent;
}());


;// CONCATENATED MODULE: ./engine/renderable/tsx/_genetic/vEngineTsxComponent.ts




var VEngineTsxComponent = (function (_super) {
    __extends(VEngineTsxComponent, _super);
    function VEngineTsxComponent(tsxDOMRenderer) {
        var _this = _super.call(this) || this;
        _this.tsxDOMRenderer = tsxDOMRenderer;
        _this.rendering = false;
        if (VEngineTsxRootHolder.ROOT) {
            VEngineTsxFactory.clean();
        }
        VEngineTsxRootHolder.ROOT = _this;
        return _this;
    }
    VEngineTsxComponent.prototype._triggerRendering = function () {
        if (this.rendering)
            return;
        this.rendering = true;
        if (this.rootNativeElement !== undefined) {
            this.rootVirtualElement = this.tsxDOMRenderer.render(this, this.rootNativeElement);
        }
        this.rendering = false;
    };
    VEngineTsxComponent.prototype.mountTo = function (root) {
        root.removeChildren();
        this.rootNativeElement = root;
        this._triggerRendering();
        this.onMounted();
    };
    VEngineTsxComponent.prototype.destroy = function () {
        VEngineTsxFactory.destroyElement(this.rootVirtualElement);
    };
    return VEngineTsxComponent;
}(BaseTsxComponent));


;// CONCATENATED MODULE: ./engine/renderable/tsx/_genetic/abstractTsxDOMRenderer.ts


var AbstractTsxDOMRenderer = (function () {
    function AbstractTsxDOMRenderer(elementCreator) {
        this.elementCreator = elementCreator;
        this.toMount = [];
    }
    AbstractTsxDOMRenderer.prototype.render = function (component, root) {
        var newVirtualNode = component.render();
        var newVirtualNodeChildren = [];
        if (newVirtualNode.type === 'virtualFragment') {
            newVirtualNodeChildren.push.apply(newVirtualNodeChildren, newVirtualNode.children);
        }
        else {
            newVirtualNodeChildren.push(newVirtualNode);
        }
        var newVirtualDom = new VirtualNode({}, 'root', newVirtualNodeChildren);
        this.reconcileChildren(newVirtualDom, this.oldVirtualDom, root);
        this.oldVirtualDom = newVirtualDom;
        for (var _i = 0, _a = this.toMount; _i < _a.length; _i++) {
            var cmp = _a[_i];
            cmp.onMounted();
        }
        this.toMount.length = 0;
        return newVirtualDom;
    };
    AbstractTsxDOMRenderer.prototype.removeNode = function (node, vNode) {
        node.removeSelf();
        VEngineTsxFactory.destroyElement(vNode);
    };
    AbstractTsxDOMRenderer.prototype.replaceNode = function (node, oldVirtualNode, newVirtualNode, parent) {
        var newNode = this.elementCreator.createElementByTagName(newVirtualNode);
        this.setGenericProps(newNode, newVirtualNode, parent);
        parent.replaceChild(node, newNode);
        VEngineTsxFactory.destroyElement(oldVirtualNode);
        return newNode;
    };
    AbstractTsxDOMRenderer.prototype.updateNode = function (node, newVirtualNode, parent) {
        this.setGenericProps(node, newVirtualNode, parent);
    };
    AbstractTsxDOMRenderer.prototype.createNode = function (newVirtualNode, parent) {
        var _a;
        var node = this.elementCreator.createElementByTagName(newVirtualNode);
        this.setGenericProps(node, newVirtualNode, parent);
        parent.appendChild(node);
        if ((_a = newVirtualNode.parentComponent) === null || _a === void 0 ? void 0 : _a.__shouldBeMounted) {
            newVirtualNode.parentComponent.__shouldBeMounted = false;
            this.toMount.push(newVirtualNode.parentComponent);
        }
        return node;
    };
    AbstractTsxDOMRenderer.prototype.reconcile = function (newVirtualNode, oldVirtualNode, realNode, parent) {
        var _a, _b;
        var newRealNode = realNode;
        if (newVirtualNode === undefined && oldVirtualNode !== undefined) {
            if (newRealNode !== undefined)
                this.removeNode(newRealNode, oldVirtualNode);
        }
        else if (newVirtualNode !== undefined && oldVirtualNode !== undefined && newRealNode !== undefined) {
            if (newVirtualNode.index !== oldVirtualNode.index ||
                ((_a = newVirtualNode.props) === null || _a === void 0 ? void 0 : _a.__id) !== ((_b = oldVirtualNode.props) === null || _b === void 0 ? void 0 : _b.__id) ||
                newVirtualNode.loopIndex !== oldVirtualNode.loopIndex ||
                newVirtualNode.tagName !== oldVirtualNode.tagName) {
                newRealNode = this.replaceNode(newRealNode, oldVirtualNode, newVirtualNode, parent);
            }
            else {
                this.updateNode(newRealNode, newVirtualNode, parent);
            }
        }
        else if (newVirtualNode !== undefined && (oldVirtualNode === undefined || newRealNode === undefined)) {
            newRealNode = this.createNode(newVirtualNode, parent);
        }
        if (newRealNode !== undefined)
            this.reconcileChildren(newVirtualNode, oldVirtualNode, newRealNode);
        return newRealNode;
    };
    AbstractTsxDOMRenderer.prototype.reconcileChildren = function (newVirtualNode, oldVirtualNode, parent) {
        var _a, _b, _c, _d, _e, _f;
        var maxNumOfChild = Math.max((_b = (_a = newVirtualNode === null || newVirtualNode === void 0 ? void 0 : newVirtualNode.children) === null || _a === void 0 ? void 0 : _a.length) !== null && _b !== void 0 ? _b : 0, (_d = (_c = oldVirtualNode === null || oldVirtualNode === void 0 ? void 0 : oldVirtualNode.children) === null || _c === void 0 ? void 0 : _c.length) !== null && _d !== void 0 ? _d : 0);
        var realChildren = [];
        for (var i = 0, max = parent.getChildrenCount(); i < max; ++i)
            realChildren.push(parent.getChildAt(i));
        for (var i = 0; i < maxNumOfChild; ++i) {
            var newVirtualChild = (_e = newVirtualNode === null || newVirtualNode === void 0 ? void 0 : newVirtualNode.children) === null || _e === void 0 ? void 0 : _e[i];
            var oldVirtualChild = (_f = oldVirtualNode === null || oldVirtualNode === void 0 ? void 0 : oldVirtualNode.children) === null || _f === void 0 ? void 0 : _f[i];
            this.reconcile(newVirtualChild, oldVirtualChild, realChildren[i], parent);
        }
    };
    AbstractTsxDOMRenderer.prototype.setGenericProps = function (model, virtualNode, parent) {
        var _a;
        if (((_a = virtualNode === null || virtualNode === void 0 ? void 0 : virtualNode.props) === null || _a === void 0 ? void 0 : _a.ref) !== undefined)
            virtualNode.props.ref(model);
        this.elementCreator.setProps(model, virtualNode, parent);
    };
    return AbstractTsxDOMRenderer;
}());


;// CONCATENATED MODULE: ./engine/renderable/tsx/_genetic/abstractElementCreator.ts
var AbstractElementCreator = (function () {
    function AbstractElementCreator() {
    }
    return AbstractElementCreator;
}());


;// CONCATENATED MODULE: ./engine/renderable/tsx/dom/internal/HTMLElementWrap.ts

var HTMLElementWrap = (function () {
    function HTMLElementWrap(htmlElement) {
        this.htmlElement = htmlElement;
        this.attributes = {};
        this._childrenCache = [];
    }
    HTMLElementWrap.prototype.appendChild = function (child) {
        if (this.htmlElement.styleSheet && !this.htmlElement.sheet) {
            this.htmlElement.styleSheet.cssText = child.htmlElement.data;
        }
        else
            this.htmlElement.appendChild(child.htmlElement);
    };
    HTMLElementWrap.prototype.removeSelf = function () {
        this.htmlElement.parentNode.removeChild(this.htmlElement);
        ElementFactory.getInstance().onElementRemoved(this.htmlElement);
    };
    HTMLElementWrap.prototype.replaceChild = function (oldNode, newNode) {
        ElementFactory.getInstance().onElementRemoved(oldNode.htmlElement);
        this.htmlElement.replaceChild(newNode.htmlElement, oldNode.htmlElement);
    };
    HTMLElementWrap.prototype.getChildAt = function (index) {
        if (this.htmlElement.nodeType === 3)
            return undefined;
        var c = this.htmlElement.childNodes[index];
        return wrap(c);
    };
    HTMLElementWrap.prototype._getChildren = function () {
        this._childrenCache.length = 0;
        for (var i = 0, l = this.htmlElement.childNodes.length; i < l; ++i) {
            var c = this.htmlElement.childNodes[i];
            this._childrenCache.push(wrap(c));
        }
        return this._childrenCache;
    };
    HTMLElementWrap.prototype.getChildrenCount = function () {
        if (this.htmlElement.nodeType === 3)
            return 0;
        return this.htmlElement.childNodes.length;
    };
    HTMLElementWrap.prototype.getParentNode = function () {
        return wrap(this.htmlElement.parentElement);
    };
    HTMLElementWrap.prototype.removeChildren = function () {
        if (this.htmlElement.nodeType === 3) {
            this.htmlElement.data = '';
        }
        this.htmlElement.innerHTML = '';
    };
    return HTMLElementWrap;
}());

var wrap = function (htmlElement) {
    return ElementFactory.getInstance().getWrapByElement(htmlElement);
};

;// CONCATENATED MODULE: ./engine/renderable/tsx/dom/internal/domElementCreator.ts




var ELEMENT_PROPERTIES = ['value', 'checked', 'selected', 'focus', 'disabled', 'readonly'];
var SPECIAL_ATTRIBUTES = ['children', '__id'];
var svgTags = ['svg', 'g', 'rect', 'path', 'circle', 'line'];
var ElementFactory = (function () {
    function ElementFactory() {
        this.elements = [];
        this.wrappers = [];
    }
    ElementFactory.getInstance = function () {
        return ElementFactory.instance;
    };
    ElementFactory.prototype.onElementCreated = function (el) {
        this.elements.push(el);
    };
    ElementFactory.prototype.onElementRemoved = function (el) {
        var indexOf = this.elements.indexOf(el);
        this.elements.splice(indexOf, 1);
        this.wrappers.splice(indexOf, 1);
    };
    ElementFactory.prototype.getWrapByElement = function (el) {
        var indexOf = this.elements.indexOf(el);
        this.wrappers[indexOf] = this.wrappers[indexOf] || new HTMLElementWrap(el);
        return this.wrappers[indexOf];
    };
    ElementFactory.instance = new ElementFactory();
    return ElementFactory;
}());

var DomElementCreator = (function (_super) {
    __extends(DomElementCreator, _super);
    function DomElementCreator() {
        return _super.call(this) || this;
    }
    DomElementCreator.prototype.createElementByTagName = function (node) {
        var htmlNode;
        if (node instanceof VirtualTextNode) {
            htmlNode = document.createTextNode(node.text);
        }
        else if (node instanceof VirtualCommentNode) {
            htmlNode = document.createComment(node.comment);
        }
        else {
            if (svgTags.indexOf(node.tagName) > -1) {
                htmlNode = document.createElementNS('http://www.w3.org/2000/svg', node.tagName);
            }
            else
                htmlNode = document.createElement(node.tagName);
        }
        ElementFactory.getInstance().onElementCreated(htmlNode);
        return new HTMLElementWrap(htmlNode);
    };
    DomElementCreator.prototype.setProps = function (model, virtualNode, parent) {
        var props = virtualNode.props;
        var el = model.htmlElement;
        if (el.nodeType === 3) {
            var virtualTextNode = virtualNode;
            if (virtualTextNode.text !== model.attributes.text) {
                model.attributes.text = virtualTextNode.text;
                el.data = virtualTextNode.text;
            }
        }
        else {
            var htmlEl_1 = el;
            var _loop_1 = function (key) {
                if (key.indexOf('on') === 0) {
                    htmlEl_1[key] = props[key];
                }
                else if (model.attributes[key] !== props[key]) {
                    model.attributes[key] = props[key];
                    var attrName = key;
                    if (SPECIAL_ATTRIBUTES.indexOf(attrName) > -1)
                        return "continue";
                    if (attrName === 'style') {
                        var styleDeclarationNew_1 = props[key];
                        if (styleDeclarationNew_1 === null || styleDeclarationNew_1 === void 0 ? void 0 : styleDeclarationNew_1.substr) {
                            htmlEl_1.setAttribute('style', styleDeclarationNew_1);
                        }
                        else {
                            var styleDeclarationOld = virtualNode.props.style;
                            Object.keys(styleDeclarationNew_1).forEach(function (k) { return htmlEl_1.style[k] = styleDeclarationNew_1[k]; });
                            Object.keys(styleDeclarationOld).forEach(function (k) {
                                if (styleDeclarationNew_1[k] === undefined)
                                    htmlEl_1.style[k] = undefined;
                            });
                        }
                        return "continue";
                    }
                    if (key === 'htmlFor')
                        attrName = 'for';
                    else if (key === 'className')
                        attrName = 'class';
                    else if (key === 'ref') {
                        virtualNode.props.ref(el);
                        return "continue";
                    }
                    if (ELEMENT_PROPERTIES.indexOf(key) > -1) {
                        htmlEl_1[key] = props[key];
                    }
                    else {
                        var value = props[key];
                        if (value === null || value === undefined)
                            htmlEl_1.removeAttribute(attrName);
                        else
                            htmlEl_1.setAttribute(attrName, props[key]);
                    }
                }
            };
            for (var _i = 0, _a = Object.keys(props); _i < _a.length; _i++) {
                var key = _a[_i];
                _loop_1(key);
            }
        }
    };
    return DomElementCreator;
}(AbstractElementCreator));


;// CONCATENATED MODULE: ./engine/renderable/tsx/dom/internal/htmlTsxDOMRenderer.ts



var HtmlTsxDOMRenderer = (function (_super) {
    __extends(HtmlTsxDOMRenderer, _super);
    function HtmlTsxDOMRenderer() {
        return _super.call(this, new DomElementCreator()) || this;
    }
    return HtmlTsxDOMRenderer;
}(AbstractTsxDOMRenderer));


;// CONCATENATED MODULE: ./engine/renderable/tsx/dom/domRootComponent.ts



var DomRootComponent = (function (_super) {
    __extends(DomRootComponent, _super);
    function DomRootComponent() {
        return _super.call(this, new HtmlTsxDOMRenderer()) || this;
    }
    return DomRootComponent;
}(VEngineTsxComponent));


;// CONCATENATED MODULE: ./src/main.widget.tsx





var MainWidget = function () {
    var _a;
    var _classSuper = DomRootComponent;
    var _instanceExtraInitializers = [];
    var _test_decorators;
    return _a = (function (_super) {
            __extends(MainWidget, _super);
            function MainWidget() {
                var _this = _super !== null && _super.apply(this, arguments) || this;
                __runInitializers(_this, _instanceExtraInitializers);
                return _this;
            }
            MainWidget.prototype.test = function (e) {
            };
            MainWidget.prototype.render = function () {
                return (VEngineTsxFactory.createElement(VEngineTsxFactory.createFragment, null,
                    VEngineTsxFactory.createElement(Frame, { title: 'Pixel Font', __id: 0 }, "test 123")));
            };
            return MainWidget;
        }(_classSuper)),
        (function () {
            var _b;
            var _metadata = typeof Symbol === "function" && Symbol.metadata ? Object.create((_b = _classSuper[Symbol.metadata]) !== null && _b !== void 0 ? _b : null) : void 0;
            _test_decorators = [Reactive.Method()];
            __esDecorate(_a, null, _test_decorators, { kind: "method", name: "test", static: false, private: false, access: { has: function (obj) { return "test" in obj; }, get: function (obj) { return obj.test; } }, metadata: _metadata }, null, _instanceExtraInitializers);
            if (_metadata) Object.defineProperty(_a, Symbol.metadata, { enumerable: true, configurable: true, writable: true, value: _metadata });
        })(),
        _a;
}();


;// CONCATENATED MODULE: ./src/index.ts


var root = document.createElement('div');
root.id = 'root';
document.body.appendChild(root);
var widget = new MainWidget();
widget.mountTo(new HTMLElementWrap(root));

/******/ })()
;
            )html"
        ) 
    }   
);
