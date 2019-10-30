let print_pyramid n =
  let rec print_spaces = function
    | 0 -> ()
    | n -> print_string " "; print_spaces (n - 1)
  in
  let rec print_stars = function
    | 0 -> ()
    | n -> print_string "*"; print_stars (n - 1)
  in
  let rec print_pyramid_inner = function
    | m when m = n -> ()
    | m ->
      print_spaces m;
      print_stars (2 * (n - m) - 1);
      print_endline "";
      print_pyramid_inner (m + 1)
  in
  print_pyramid_inner 0

let _ = print_pyramid (read_int ())
