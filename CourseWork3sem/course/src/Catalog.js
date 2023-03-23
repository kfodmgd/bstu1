import {SortTable} from "./items/SortTable";
import React, {useRef, useState} from "react";
import {content} from "./items//Content";
import {Search} from "./items/Search";
import './style/css/sortTable.css'

import { CartProvider, useCart } from "react-use-cart";

function Page() {
  const { addItem } = useCart();
  const [isShown, setIsShown] = useState(false);
  const [array, setArray] = useState(content);
  const [search, setSearch] = useState('');
  const [sorted, setSorted] = useState({name: true, price: true, discount: true});
  const [searchParameter, setSearchParameter] = useState('partial');

  const [items,cart]=useState([]);

  const products = content;

    const sort = (byWhat) => {
        let direction = sorted[byWhat] ? 1 : -1,
            goodsCopy = [...array].sort(function (a, b) {
                if (a.new || b.new)
                    return 0
                if (a[byWhat] > b[byWhat]) {
                    return direction;
                }
                if (a[byWhat] < b[byWhat]) {
                    return direction * -1;
                }
                return 0;
            });
        sorted[byWhat] = !sorted[byWhat];
        setArray(goodsCopy);
    }
    const sorts = () => {
        for(let i=0;i<content.lengh;i++){
            if(content[i].discount!=false){
                content[i].push(content[i].prdis=((content[i].price * (100 - content[i].discount)) / 100))
            }else{
                content[i].push(content[i].prdis=content[i].price)
            }
        }
        return (
            <div className="sorts">
                <button className="btt" onClick={() => sort("name")}>
                    Name
                </button>
                <button className="btt" onClick={() => sort("price")}>
                    Price
                </button>
                <button className="btt" onClick={() => sort("discount")}>
                    Discount
                </button>
            </div>
        );
    }
    const goods = () => {
        return array
            .filter((item) => {
                if (!search) return item;
                if (
                    item.name.toLowerCase().includes(search.toLowerCase())
                ) {
                    return item;
                }
            })
            .map((item) => {
                return (
                <>
                    {<div className="oneGood" key={item.id}>
                        <div className="wrapper">
                            <div className="imgDesc"
                                onMouseEnter={() => setIsShown(true)}
                                onMouseLeave={() => setIsShown(false)}>                                
                                <img className="image" src={item.img} alt=""/>                                
                                 {isShown &&(<div className="dsc">{item.desc}</div>)}
                            </div>
                        <div className="text">
                            <div className="name">{item.name}</div>
                            <div className="bot">
                                <button className="cart" onClick={() => addItem(item)} >Cart</button>
                                {item.discount!=false ? 
                                    <div className="prices">
                                        <label className="dsk">{Math.ceil(((item.price * (100 - item.discount)) / 100)*100)/100}$</label>
                                        <label className="lb">{item.price}$</label>
                                    </div>    
                                    :
                                    <div className="prices">
                                        <label className="dsk1">{Math.ceil(((item.price * (100 - item.discount)) / 100)*100)/100}$</label>
                                    </div>
                                }
                            </div>                        
                        </div>
                        </div>
                    </div>
                    }   
                </>
            );
        });
    }
  return (
        <>
            <div className='assort'>
                <div className="left">
                <Search search={setSearch} searchParameter={setSearchParameter} />
                <div>Type</div>
                <hr/>
                <ul>
                    <li>Red</li>
                    <li>Green</li>
                    <li>White</li>
                    <li>Yellow</li>
                    <li>Additions</li>
                </ul>
                </div>
                <div className="assortiment">
                    <div className='hed'>Teas&Additions</div>
                    <div className="Item">
                        {sorts()}
                        <div className="goods">
                            {goods()}
                        </div>
                    </div>
                </div>
            </div>
        </>
    );
  }

  export const Catalog=()=> {
    return (
      <CartProvider>
        <Page />
      </CartProvider>
    );
  }
  export default Catalog;