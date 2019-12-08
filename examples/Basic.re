open Server.App;
open Thunder;

get("/", (_request) => {
  { code: 200, body: Js.Json.string("Root Path") }
})

get("/test", (_request) => {
  // Same as { code: 200, body: Js.Json.string("Test Path") }
  Response.(
    make()
    -> setCode(200)
    -> setBody(Js.Json.string("Test Path"))
  )
})