use crossterm::terminal::size;
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let numsize = &args[1];

    let gensize: u128 = numsize.parse().unwrap();
    let strnum = random_string(gensize);
    let sum = reduce_number(strnum, gensize, true);
    println!("{}", sum);
}

fn reduce_number(num_in: String, gensize: u128, print_flag: bool) -> String {
    let mut strnum = num_in.clone();
    let (columns, _rows) = get_terminal_size();

    // if size is greater than terminal width, dont print
    if print_flag {
        if gensize > columns as u128 {
            println!("Number of size {} is too large to print", gensize);
        } else {
            println!("{}", strnum);
        }
    }

    let mut sum = add_digits(strnum.clone());
    if print_flag {
        println!("{}", sum);
    }

    while sum > 9 {
        strnum = sum.to_string();
        sum = add_digits(strnum.clone());
        if print_flag {
            println!("{}", sum);
        }
    }

    sum.to_string()
}

fn get_terminal_size() -> (u16, u16) {
    let (columns, _rows) = size().unwrap();
    (columns, _rows)
}

fn random_string(size: u128) -> String {
    let mut strnum = String::new();
    for _ in 0..size {
        let mut num = rand::random::<u8>();
        num %= 9;
        strnum.push_str(&num.to_string());
    }

    // make sure last digit is odd
    let last_digit = strnum.chars().last().unwrap();
    let last_digit = last_digit.to_digit(10).unwrap();
    if last_digit % 2 == 0 {
        let num = rand::random::<u8>();
        strnum.push_str(&num.to_string());
    }

    strnum
}

fn add_digits(num: String) -> u128 {
    let mut sum = 0;
    for c in num.chars() {
        let digit = c.to_digit(10).unwrap();
        sum += digit as u128;
    }
    sum
}
