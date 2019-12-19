open Thunder;

let root =
  get("/", _request => `String("Thunder API up and running!") |> respond);

let mirror =
  post("/mirror", request => `Json(request.body) |> respond);

let xml =
  get("/xml") @@
  (_request) => {
    `Xml("<?xml version=\"1.0\" encoding=\"UTF-8\"?>
    <email>
      <to>Thunder Web Framework</to>
      <from>Yusuf YILDIRIM</from>
      <subject>XML Test</subject>
      <body>It works!</body>
    </email>
    ") |> respond;
  }

let customHeader =
  get("/header") @@
  (_request) => {
    let headers = Header.empty()
      -> Header.set("Custom-Header", "Test");

    `String("Custom-Header looks good!") |> respond(~headers);
  }

let routes = [ root, mirror, xml, customHeader ];
let controller = Controller.make(~routes);

let make = Module.make(~controllers = [ controller ]);