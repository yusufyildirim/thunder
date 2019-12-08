# ⚡ Thunder ⚡
A web framework on top of Fastify.

## Design Goals

* Thunder should be and easily learnable.

* It should provide developer-friendly packages and helpers to minimize friction and improve developer productivity.

## Examples

More examples will be available in the `/examples` folder.

### Basic

``` reason
module App = Thunder.Make({
    let port = 3000;
});

open App;

get("/", (_request) => {
    { code: 200, body: Js.Json.string("Hello World") }
})

App.listen();
```