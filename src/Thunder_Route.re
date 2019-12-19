type t = {
  meth: Thunder_Code.methods,
  path: string,
  handler: Thunder_Handler.t
}

let make = (~meth, ~path, ~handler) => {
  meth,
  path,
  handler,
};
