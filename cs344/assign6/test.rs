
//use std::env; // to get arugments passed to the program

fn str_len(x : String) -> usize {
  x.len()
}

fn main() {
  let s = String::from("Hello");
  let len = str_len(s);
  println!("Length of {} is {}", s, len);

}









