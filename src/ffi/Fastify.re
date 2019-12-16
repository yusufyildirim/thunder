type instance;
type p('a)
// query, params and headers should be Js.Dict but Js.Json is relatively more easy to work with. e.g validation
type request = {
  body: Js.Json.t,
  query: Js.Dict.t(string),
  params: Js.Dict.t(string),
  headers: Js.Dict.t(string),
  ip: string,
  hostname: string,
};

type response;
type handler = (request, response) => unit;

type serverOptions = {
  http2: bool,
  logger: bool,
};


let createServerOptions = (
  ~http2: option(bool) = ?,
  ~logger: option(bool) = ?,
  (),
): serverOptions =>
  {
    http2: Belt.Option.getWithDefault(http2, false),
    logger: Belt.Option.getWithDefault(logger, false),
  };

type route = {
  [@bs.as "method"] meth: string,
  [@bs.as "url"] route: string,
  handler: handler,
};

[@bs.module] external fastify: serverOptions => instance = "fastify";
[@bs.send.pipe: instance] external route: route => unit = "route";
[@bs.send.pipe: instance] external listen: int => unit = "listen";
[@bs.send.pipe: response] external sendJson: Js.Json.t => unit = "send";
[@bs.send.pipe: response] external sendString: string => unit = "send";
[@bs.send.pipe: response] external setCode: int => unit = "code";
[@bs.send.pipe: response] external setHeader: string => unit = "header";
[@bs.send.pipe: response] external setHeaders: Js.Dict.t(string) => unit = "headers";


/* *** PLUGIN *** */

type pluginOptions;
type pluginDone = unit => unit;
type plugin = (instance, pluginOptions, pluginDone) => unit;

[@bs.send.pipe: instance] external register: plugin => unit = "register";