open Thunder;

let create =
  post("/user/create") @@
  (request) => {
    let user = User_Service.user_decode(request.body) -> Belt.Result.getExn;

    User_Service.create(user);
    `String("Created!") |> respond;
  };

let findAll =
  get("/user/findAll") @@
  (_request) => {
    let users = User_Service.findAll();

    `Json(User_Service.userList_encode(users)) |> respond;
  }

let routes = [ create, findAll ];
let make = Controller.make(~routes);