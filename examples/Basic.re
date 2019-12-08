open Server.App;
open Thunder;

get("/", (_request) => {
    { code: 200, body: Js.Json.string("Root Path") }
})

get("/test", (_request) => {
    { code: 200, body: Js.Json.string("Test Path") }
})