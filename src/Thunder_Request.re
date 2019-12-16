 type t = {
  body: Js.Json.t,
  query: Js.Dict.t(string),
  params: Js.Dict.t(string),
  headers: Js.Dict.t(string),
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

let param = (request: t, key) =>  {
  Js.Dict.get(request.params, key);
}