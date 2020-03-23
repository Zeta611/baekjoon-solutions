let wc_match wc name =
  let memo = Array.make_matrix 101 101 None in
  let len_wc = String.length wc in
  let len_name = String.length name in
  let rec loop i_wc i_name =
    match memo.(i_wc).(i_name) with
    | Some true -> true
    | Some false -> false
    | None ->
      let subst b =
        memo.(i_wc).(i_name) <- Some b;
        b
      in
      if i_name = len_name then
        if i_wc = len_wc then subst true
        else if wc.[i_wc] = '*' then subst (loop (i_wc + 1) i_name)
        else subst false
      else
        if i_wc = len_wc then subst false
        else
          match wc.[i_wc] with
          | '*' -> subst (loop i_wc (i_name + 1) || loop (i_wc + 1) i_name)
          | '?' -> subst (loop (i_wc + 1) (i_name + 1))
          | c when c = name.[i_name] -> subst (loop (i_wc + 1) (i_name + 1))
          | _ -> subst false
  in
  loop 0 0

let () =
  let wc = read_line () in
  let n_files = int_of_string (read_line ()) in
  let rec loop i =
    if i = n_files then () else
    let file = read_line () in
    if wc_match wc file then print_endline file else ();
    loop (i + 1)
  in
  loop 0
