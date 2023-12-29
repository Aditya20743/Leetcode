/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    let t= await new Promise(resolve =>(setTimeout(resolve,millis)));
    
    
    return t;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */