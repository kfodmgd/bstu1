import './style/css/assort.css';
import {Link} from 'react-router-dom';
import {Catalog} from './Catalog';

export const Assort=()=>{
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
        <body>
        <Catalog/>
        <div class="rain front-row"></div>
            <div class="rain back-row"></div>
            <div class="toggles">
        </div>
        </body>
        <footer>
            <hr className="hrT"/>
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
export default Assort;