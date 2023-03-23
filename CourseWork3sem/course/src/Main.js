import back from './photo/back.png';
import red from './photo/red.jpg';
import white from './photo/white.jpg';
import yellow from './photo/yellow.jpg';
import green from './photo/green.jpg';
import black from './photo/black.jpg';
import additives from './photo/additivies.jpg';

import './style/css/main.css';

import {Link} from 'react-router-dom';
import React from 'react';


export class Main extends React.Component {
    state = {
        name: "",
        com:"",
        mail:"",
    };
    onChange=(e)=>{
        this.setState({name:e.target.value});
        };
    onChange1=(e)=>{
        this.setState({com:e.target.value});
    };
    onChange2=(e)=>{
        this.setState({mail:e.target.value});
    };

    render() {       
  return (
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
        <div className="rectangle">
            <img className="imgRec" src={back}/>
            <div className="txt">A real tea bouquet is like an expensive wine, it cannot be repeated, the secrets of 
                its preparation are available only to the author.</div>
        </div>

        <div className="box">
            <div className="assort1">
                <Link to='/Assort' className="txtAs">Green Tea</Link>
                <img src={green}/>
            </div>
            <div className="assort2">
                <Link to='/Assort' className="txtAs">Black Tea</Link>
                <img src={black}/>
            </div>
            <div className="assort3">
                <Link to='/Assort' className="txtAs">Red Tea</Link>
                <img src={red}/>
            </div>
            <div className="assort4">
                <Link to='/Assort' className="txtAs">White Tea</Link>
                <img src={white}/>
            </div>
            <div className="assort5">
                <Link to='/Assort' className="txtAs">Yellow Tea</Link>
                <img src={yellow}/>
            </div>
            <div className="assort6">
                <Link to='/Assort' className="txtAs">Additives</Link>
                <img src={additives}/>
            </div>
        </div>
        
        <div className="preBottom">
            <div className="desc">SpecialTea<br/><br/>SpecialTea is a Virginia-based tea compony sourcing onlu the highest quality tea, herbs, and 
                spices from around the world</div>
            <div className="email">
                <div className="emailDisc">Sing up and get 10% off your first purchase:</div>
            <br/>
            <form id="form1">
            Name
                <input type="text" className="mail" name='name' value={this.state.name} onChange={this.onChange}/>
            Comment
                <input type="text" className="mail" name='com' value={this.state.com} onChange={this.onChange1}/>  
            E-mail  
                <input type="text" className="mail"  name='value' value={this.state.mail} onChange={this.onChange2}/>
                <br/>            
                <button className='send' type="submit">Send</button>
            </form>
            </div>
        </div>

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
    </body>
</html>
  );
}
}
