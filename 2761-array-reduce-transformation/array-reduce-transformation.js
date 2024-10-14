/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */

//  recurssion
  function f(nums,fn,init,i){
        if(i==nums.length)return init;

        return f(nums,fn,fn(init,nums[i]),i+1);
    }
    
var reduce = function(nums, fn, init) {
    // let val=init;
    // for(let i=0;i<nums.length;i++){
    //     val=fn(val,nums[i]);
    // }

    // return val;

    return f(nums,fn,init,0);
};