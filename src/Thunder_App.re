
module type config = {
  let port: int;
  let modules: list(Thunder_Module.t);
};


module Make = (CONF: config) => {
  open CONF;

  let options = Fastify.createServerOptions(~logger = true, ());
  let app = Fastify.fastify(options);

  let registerRoute = (route: Thunder_Route.t) => {
    let meth = Thunder_Code.stringOfMeth(route.meth);
    let handler = Fastify.makeHandler(route.handler);

    app |> Fastify.route({ meth, path: route.path, handler });
  }

  let registerRoutes = (routes: list(Thunder_Route.t)) => {
    routes |> List.iter(route => registerRoute(route));
  }

  let registerController = (controller: Thunder_Controller.t) => {
    registerRoutes(controller.routes);
  }

  let registerControllers = (controllers: list(Thunder_Controller.t)) => {
    controllers |> List.iter(controller => registerController(controller))
  }

  let registerModules = () => {
    modules |> List.iter((_module: Thunder_Module.t) => registerControllers(_module.controllers));
  }

  let listen = () => {
    app |> Fastify.listen(port);
  }

  registerModules();
}