open Thunder.App;

module App = Make({
  let port = 3000;
  let modules = [
    Empty.make,
    Basic.make,
    User.make,
  ];
});

App.listen();