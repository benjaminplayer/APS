let sidebar_list_items = document.querySelectorAll(".side_bar_list_item");

function getSubDepth(element)
{
    let d = 0;
    while (element.classList.contains("sub"))
    {
        d++;
        element = element.parentElement;
    }

    return d;
}

function getSubLists(parent, element)
{
    let ch = [];
    let i = 0;
    for (let child of parent.children)
    {
        if(child.classList.contains("sub") && child != element)
        {
            ch[i] = child;
            if(!child.classList.toString().includes("depth"))
            {
                console.log("no depth data");
                child.classList.add("d"+getSubDepth(child)); // popravi da da na child depth
            }
        }
    }
    return (ch.length > 0)? ch : null;
}

function expand_list(el)
{
    console.log(el);
    el.classList.toggle("expanded");
    let sub_lists = getSubLists(el.parentElement, el); // parent element is the container
    console.log(sub_lists);

    if (sub_lists != null)
        sub_lists.forEach(child=>{
            child.classList.toggle("active")
        });

}

