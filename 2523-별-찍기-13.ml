let print_pyramid n =
  let rec print_stars = function
    | 0 -> ()
    | n -> print_string "*"; print_stars (n - 1)
  in
  let rec print_pyramid_top = function
    | 0 -> ()
    | m ->
      print_stars (n - m + 1);
      print_endline "";
      print_pyramid_top (m - 1)
  in
  let rec print_pyramid_bottom = function
    | 0 -> ()
    | m ->
      print_stars m;
      print_endline "";
      print_pyramid_bottom (m - 1)
  in
  print_pyramid_top n;
  print_pyramid_bottom (n - 1)

let _ = print_pyramid (read_int ())
