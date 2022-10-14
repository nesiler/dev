function consoleStuff() {

    console.clear()

    console.log("Codarch")

    console.warn("Shit here we go again...")
    console.error("Access Denied - Bad things happen")

    console.time("start")
    console.log(Math.pow(Math.random(), Math.random()))
    console.timeEnd("start")

    //console.table({ isim: "Enes", soyisim: "Diler" })

    let number = parseInt(prompt("Enter a number"))

    console.log("Number squared: " + Math.pow(number, 2))

    //alert("Look at the console!")
}

function variables() {

    let num = 123

    console.log(typeof num)
    console.log("55" == 55) // == sadece değerleri kontrol eder
    console.log("60" === 60) // === değeri ve veri tipini kontrol eder 

    //tarnery if usage
    let a = 15, b = 8, c
    c = (a > b) ? (a + b) : (a - b)
    console.log("C : " + c)

    let res = parseInt(prompt("Enter a Number (for factorial)"))
    console.log(fak(res))
}

function fak(num) {
    if (num >= 1)
        return num * fak(num - 1)
    else
        return 1
}

//Simple function definition
fatArrow = _ => {
    console.log("Inside of Arrow Function...")
}

//Shortest Function
shortestFunction = number => console.log(number)

function arrayThings() {

    let list = ["One", "Two", "Three", "Four", "Five"]

    for (let i = 0; i < list.length; i++) {
        console.log(list[i])
    }

    console.log("**********************")

    for (let number in list) {
        console.log(list[number])
    }
    //add element to the end
    list.push("Six")

    console.log(list.toString())

    //delete last element, returns the deleted element
    list.pop();
    //delete the first element, returns the deleted element
    list.shift();

    //adds an element to the beginning of the list
    list.unshift("Zero");

    //delete what ever you want
    delete list[3];

    //print the array as you want
    console.log(list.join("/ "))
}


