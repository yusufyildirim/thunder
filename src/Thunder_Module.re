type t = {
  controllers: list(Thunder_Controller.t),
};

let make = (~controllers) => {
  controllers: controllers,
};
