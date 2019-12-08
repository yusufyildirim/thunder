type instance;
type p('a)
// query, params and headers should be Js.Dict but Js.Json is relatively more easy to work with. e.g validation
type request = {
  body: Js.Json.t,
  query: Js.Json.t,
  params: Js.Json.t,
  headers: Js.Json.t, 
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

[@bs.module] external fastify: serverOptions => instance = "fastify";
[@bs.send.pipe: instance] external get: (string, handler) => unit = "get";
[@bs.send.pipe: instance] external post: (string, handler) => unit = "post";
[@bs.send.pipe: instance] external listen: int => unit = "listen";
[@bs.send.pipe: response] external sendJson: Js.Json.t => unit = "send";


/* *** PLUGIN *** */

type pluginOptions;
type pluginDone = unit => unit;
type plugin = (instance, pluginOptions, pluginDone) => unit;

[@bs.send.pipe: instance] external register: plugin => unit = "register";