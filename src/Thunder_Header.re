type t = Js.Dict.t(string);

let empty = Js.Dict.empty;

let set = (t, key, value) => {
  t -> Js.Dict.set(key, value);
  t;
}
let setOpt = (t: option(t), key, value) => {
  switch t {
  | None => empty() -> set(key, value)
  | Some(a) => set(a, key, value)
  };
}