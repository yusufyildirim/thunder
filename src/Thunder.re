type httpCodes = int;
module Request = {
  type t = {
    body: Js.Json.t,
    query: Js.Json.t,
    params: Js.Json.t,
    headers: Js.Json.t,
    ip: string,
    hostname: string,
  };

  let make = (~body, ~query, ~params, ~headers, ~ip, ~hostname) => {
    body,
    query,
    params,
    headers,
    ip,
    hostname,
  }
};

module Response = {
  type body = Js.Json.t;
  type t = {
    code: httpCodes,
    body,
  };

  let make = (~code = 200, ~body = Js.Json.string(""), ()) => {
    code,
    body,
  };

  let setCode = (r: t, code) => {...r, code };
  let setBody = (r: t, body) => {...r, body };
};

module Handler = {
  type t = Request.t => Response.t;
};

module type config = {
  let port: int;
};

module Make = (CONF: config) => {
  open CONF;

  let options = Fastify.createServerOptions(~logger = true, ());
  let app = Fastify.fastify(options);

  let listen = () => {
    app |> Fastify.listen(port);
  }

  let handler = (cb: Handler.t, request: Fastify.request, response: Fastify.response) => {
    let r = Request.make(
    ~body = request.body,
    ~query = request.query,
    ~params = request.params,
    ~headers = request.headers,
    ~ip = request.ip,
    ~hostname = request.hostname
    );

    let result = cb(r);

    response |> Fastify.sendJson(result.body);
  }

  let get = (route: string, cb: Handler.t) => app |> Fastify.get(route, handler(cb));
  let post = (route: string, cb: Handler.t) => app |> Fastify.post(route, handler(cb));
}