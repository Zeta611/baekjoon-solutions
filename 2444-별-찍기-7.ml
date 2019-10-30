let print_pyramid n =
  let rec print_spaces = function
    | 0 -> ()
    | n -> print_string " "; print_spaces (n - 1)
  in
  let rec print_stars = function
    | 0 -> ()
    | n -> print_string "*"; print_stars (n - 1)
  in
  let rec print_pyramid_top = function
    | 0 -> ()
    | m ->
      print_spaces m;
      print_stars (2 * (n - m) - 1);
      print_endline "";
      print_pyramid_top (m - 1)
  in
  let rec print_pyramid_bottom = function
    | m when m = n -> ()
    | m ->
      print_spaces m;
      print_stars (2 * (n - m) - 1);
      print_endline "";
      print_pyramid_bottom (m + 1)
  in
  print_pyramid_top (n - 1);
  print_pyramid_bottom 0

let _ = print_pyramid (read_int ())
