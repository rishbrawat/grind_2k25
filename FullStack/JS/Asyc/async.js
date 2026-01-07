/*
    javascript runs on single thread: which means one call stack, one thing executing at a time, no true parallel execution of the code
*/

// setTimeOut: tells the browser to run function no earlier than n seconds , when js is free
// console.log("start");
// setTimeout(() => {
//     console.log("mid");
// }, 1000);
// console.log("end"); // this executed immediately
// // the callback is registered with the browser, and js moves immediately, it does not wait, its async behaviour

// // setInterval(): run the function again and again every n milliseconds, but it does not guarentee exact timing as if js gets busy intervals are delayed
// let count = 0;
// setInterval(()=> {
//     console.log(`${count++}`);
// }, 1000);

// at minimal level js has
// callstack: 1 callstack where js code runs, only 1 function at a time
// queues of pending work: callbacks are here stored in a queue
// the event loop: the loop that constantly checks if the call stack is empty and calls the next callback from the queue onto the stack


// async : placing this before a function makes sure that the fn always returns the promise
// await: used inside the async fn, pauses the execution of the function untill the promise is resolved
// fetch: when we use fetch it actually fetches the raw object data from the api

// await fetch() waits for the server to say i am here and send headers
// await response.json parses the response into json format 

async function getUserData() {
    try {
        const response = await fetch('https://jsonplaceholder.typicode.com/posts/1');
        if(!response.ok) {
            throw new Error(`http status error ${response.statusText}`);
        }

        const data = await response.json();
        console.log(data);
    } catch(er) {
        console.log('errors: ' + er);
    }
}
getUserData();