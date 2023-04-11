let arr = [3, 5, 2, 10, 6, 8, 1, 4];
let stack = [];

let top = -1;

const find_greatest_to_left = () => {
  arr.forEach((ele) => {
    while (top != -1 && stack[top] <= ele) {
      top = top - 1;
    }
    if (top == -1) {
      console.log("-1 ");
    } else {
      console.log(stack[top]);
    }
    top +=1;
    stack.push(ele);
  });
};
find_greatest_to_left()

const find_greatest_to_right = () => {
   for(let i = arr.length - 1 ; i > 0 ; i--){
    while (top != -1 && stack[top] <= arr[i]) {
      top = top - 1;
    }
    if (top == -1) {
        console.log("-1 ");
    } else {
        console.log("%d ", peek());
    }
    stack.push(arr[i]);
  }
};

