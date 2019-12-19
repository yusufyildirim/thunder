[@decco]
type user = {
  username: string,
  password: string,
};

[@decco.encode]
type userList = list(user);

let users = ref([]);

let create = (user: user) => {
  users := [user, ...users^];
}

let findAll = () => users^;