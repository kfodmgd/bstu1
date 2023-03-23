import {Link} from 'react-router-dom';
import './style/css/cart.css';
import { CartProvider, useCart } from "react-use-cart";

export function Cart() {
  const {
    isEmpty,
    totalUniqueItems,
    items,
    updateItemQuantity,
    removeItem,
    cartTotal,
  } = useCart();
  if (isEmpty) return <p className='empty'>Your cart is empty</p>;
  return (
    <>
      <h1>Your Cart</h1>
      <div className='cartTbl'>
      <div className='cartUl'>
        <div className='crtItem1'>Count</div><div className='crtItem1'> Name</div><div className='crtItem1'> Price</div><div className='crtItem1'></div>
      </div>
        {items.map((item) => (
          <div className="cartUl">
            <div key={item.id} className='crtItem1'>
              {item.quantity} 
            </div> 
            <div className='crtItem1'>
              {item.name}
            </div>
            <div className='crtItem1'>
              {Math.ceil(((item.price * (100 - item.discount)) / 100)*100)/100}$
            </div>
            <div className='crtItem1'>  
              <button onClick={() => updateItemQuantity(item.id, item.quantity - 1)}className="crtbt">
                -
              </button>
              <button onClick={() => updateItemQuantity(item.id, item.quantity + 1)} className="crtbt">
                +
              </button>
              <button onClick={() => removeItem(item.id)}className="crtbt">&times;</button>
            </div>
          </div>
        ))}
        <p className='total'>Total ptice:{Math.ceil(cartTotal*100)/100}</p>
        <form>
          <input type="text" className="buytxt" value="Name"/>
          <input type="text" className="buytxt" value="Comments"/>   
          <input type="text" className="buytxt" value="Your    email    address..."/>             
          <button className='buy'>Buy</button>
        </form>
      </div>
    </>
  );
}

export const Crt=()=>{
    return(
        <html>
    <header>
        <div className="header">
            <Link to="/" className="logo">Special Tea</Link>
                <ul className="container">
                <Link to='/Assort' className="Item1">Assortment</Link>
                <Link to='/Cart' className="Item1">Your Cart</Link>
                <Link to='/About' className="Item1">About Us</Link>
                </ul>
        </div>
    </header>
    <CartProvider>
    <Cart/>
    </CartProvider>
    <footer>
            <div className="fTop">
            <ul className="footerTop">
                <li>Shop</li>
                <hr className="hr"/>
                <Link to='/Assort' className='lnk'>All</Link>
                <Link to='/Assort' className='lnk'>Tea</Link>
                <Link to='/Assort' className='lnk'>Additives</Link>
            </ul>
            <ul className="footerTop">
                <li>Share</li>
                <hr className="hr"/>
                <a href="https://www.instagram.com/" className='lnk'>Instagram</a>
                <a href="https://google.com" className='lnk'>Site</a>
            </ul>
            <ul className="footerTop">
                <li>Account</li>
                <hr className="hr"/>
                <Link to='/Cart' className='lnk'>Cart</Link>
            </ul>
            <ul className="footerTop">
                <li>Legal</li>
                <hr className="hr"/>
                <li className='lnk'>Terms & Conditions</li>
                <li className='lnk'>Privaty Policy</li>
            </ul>
            </div>
        </footer>
        </html>
        );
}
export default Crt;