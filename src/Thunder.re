module Code = Thunder_Code;
module Body = Thunder_Body;
module Header = Thunder_Header;
module Request = Thunder_Request;
module Response = Thunder_Response;
module Handler = Thunder_Handler;

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

  let _toFastifyHandler = (cb: Handler.t, request: Fastify.request, response: Fastify.response) => {
    let r = Request.make(
    ~body = request.body,
    ~query = request.query,
    ~params = request.params,
    ~headers = request.headers,
    ~ip = request.ip,
    ~hostname = request.hostname
    );

    let result = cb(r);

    let code = result.code -> Code.codeOfStatus;
    response |> Fastify.setCode(code);
    response |> Fastify.setHeaders(result.headers);

    switch result.body {
    | `Json(json) => response |> Fastify.sendJson(json)
    | `Xml(str)
    | `String(str) => response |> Fastify.sendString(str)
    }
  }

  let registerHandler = (~meth: Code.methods, ~route: string, ~handler: Handler.t) => {
    let meth = Code.stringOfMeth(meth);
    let handler = _toFastifyHandler(handler);

    app |> Fastify.route({ meth, route, handler });
  }

  let get = (route: string, handler: Handler.t) => registerHandler(~meth = `GET, ~route, ~handler);
  let post = (route: string, handler: Handler.t) => registerHandler(~meth = `POST, ~route, ~handler);
  let head = (route: string, handler: Handler.t) => registerHandler(~meth = `HEAD, ~route, ~handler);
  let delete = (route: string, handler: Handler.t) => registerHandler(~meth = `DELETE, ~route, ~handler);
  let patch = (route: string, handler: Handler.t) => registerHandler(~meth = `PATCH, ~route, ~handler);
  let put = (route: string, handler: Handler.t) => registerHandler(~meth = `PUT, ~route, ~handler);
  let options = (route: string, handler: Handler.t) => registerHandler(~meth = `OPTIONS, ~route, ~handler);

  // Response Helpers
  let respond = (~code: Code.statusCode = `OK, ~headers: option(Header.t) = ?, body: Body.t) => {
    let headers = 
      switch body {
      | `Json(_) => Header.setOpt(headers, "Content-Type", "application/json")
      | `String(_) => Header.setOpt(headers, "Content-Type", "text/plain")
      | `Xml(_) => Header.setOpt(headers, "Content-Type", "application/xml")
      };

    Response.make(~code, ~headers, ~body);
  }

// Request Helpers
  let param = Request.param;
}