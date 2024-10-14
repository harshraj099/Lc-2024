/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    
//    return await promise1+ await promise2;
// or

    let [v1,v2]=await Promise.all([promise1,promise2]);

    return v1+v2;
};

    // let addTwoPromises= async function(promise1,promise2){

    // };

    // for my practice
    // addTwoPromises(promise.resolve(5),promise.resolve(6))
    // .then(console.log);
/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */