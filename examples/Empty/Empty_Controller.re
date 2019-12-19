open Thunder;

let root =
  get("/empty", _request => `String("Empty module works!") |> respond);

let routes = [ root ];
let make = Controller.make(~routes);