open Server.App;
open Thunder;

get("/", _request => `String("Thunder API up and running!") |> respond);

post("/mirror", request => `Json(request.body) |> respond);

get("/xml") @@
(_request) => {
  `Xml("<?xml version=\"1.0\" encoding=\"UTF-8\"?>
  <email>
    <to>Jane</to>
    <from>Yusuf Yıldırım</from>
    <subject>XML Test</subject>
    <body>It works!</body>
  </email>
  ") |> respond;
}

get("/header") @@
(_request) => {
  let headers = Header.empty()
    -> Header.set("Custom-Header", "Test");

  `String("Custom-Header looks good!") |> respond(~headers);
}
