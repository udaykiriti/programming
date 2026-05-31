use std::io::{self,Read};

fn solve<'a>(iter: &mut std::str::SplitWhitespace) {
    let n:i64 = iter.next().unwrap().parse().unwrap();
    let k:i64 = iter.next().unwrap().parse().unwrap();

    let done = (k-1)/(n-1);
    let ans = k+done;
    println!("{}",ans );

}

fn main() {
    let mut input = String::new();

    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.split_whitespace();

    //let t = 1usize;

    if let Some(t_str) = iter.next() {
        let t: usize = t_str.parse().unwrap();
        for _ in 0..t {
            solve(&mut iter);
        }
    }
}
