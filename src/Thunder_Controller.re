type t = {
  routes: list(Thunder_Route.t),
};

let make = (~routes) => {
  routes: routes,
};
