type t = [`Json(Js.Json.t) | `String(string) | `Xml(string)];

let toString = (body: t) => {
  switch body {
    | `Xml(s)
    | `String(s) => s
    | `Json(json) => Js.Json.stringify(json)
  };
}