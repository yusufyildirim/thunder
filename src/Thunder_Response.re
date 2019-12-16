type t = {
  code: Thunder_Code.statusCode,
  body: Thunder_Body.t,
  headers: Thunder_Header.t,
};

let make = (~code = `OK, ~headers = Thunder_Header.empty(), ~body) => {
  code,
  body,
  headers,
};