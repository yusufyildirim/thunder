module Code = Thunder_Code;
module Body = Thunder_Body;
module Header = Thunder_Header;
module Request = Thunder_Request;
module Response = Thunder_Response;
module Route = Thunder_Route;
module Handler = Thunder_Handler;
module Controller = Thunder_Controller;
module Module = Thunder_Module;
module App = Thunder_App;

let get = (path: string, handler: Handler.t) => Route.make(~meth = `GET, ~path, ~handler);
let post = (path: string, handler: Handler.t) => Route.make(~meth = `POST, ~path, ~handler);
let head = (path: string, handler: Handler.t) => Route.make(~meth = `HEAD, ~path, ~handler);
let delete = (path: string, handler: Handler.t) => Route.make(~meth = `DELETE, ~path, ~handler);
let patch = (path: string, handler: Handler.t) => Route.make(~meth = `PATCH, ~path, ~handler);
let put = (path: string, handler: Handler.t) => Route.make(~meth = `PUT, ~path, ~handler);
let options = (path: string, handler: Handler.t) => Route.make(~meth = `OPTIONS, ~path, ~handler);


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