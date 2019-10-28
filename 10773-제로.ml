let eval x = int_of_string (read_line x)
let rec solve n stack =
  match n with
  | 0 -> List.fold_left (+) 0 stack
  | n ->
    begin
      match eval () with
      | 0 -> solve (n - 1) (List.tl stack)
      | m -> solve (n - 1) (m :: stack)
    end

let _ = print_int (solve (eval ()) [])
