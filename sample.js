function flatten_array(arr)
{
    let result=[];

    for(let item of arr)
    {
        if(Array.isArray(item))
        {
            result = result.concat(flatten_array(item));
        }
        else{
            result.push(item);
        }
    }

    return result;
}

const arr=[1,[2,[3,4]]];
console.log(flatten_array(arr));
