let check x y =
  if x > 0 && y > 0 then 1
  else if x < 0 && y > 0 then 2
  else if x < 0 && y < 0 then 3
  else 4

let () =
  let x = read_int () in
  let y = read_int () in
  print_endline (string_of_int (check x y))
