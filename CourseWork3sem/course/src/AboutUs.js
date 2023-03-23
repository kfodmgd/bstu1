import {Link} from 'react-router-dom';
import './style/css/aboutUs.css'

export const About=()=>{
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
            <div className='abTop'>About Us</div>
            <div className="about">
            The tea plantation is not just a proper tea shop in Minsk. This is a team of like-minded people who are completely and irrevocably in love with the 
            legendary and unique drink - tea.
            <br/>
            <br/>
            For more than five years, we have been carefully choosing only the best tea plantation producers around the world, from where we subsequently directly 
            import tea to Belarus. We do not work with intermediaries - each tea leaf passes our strict control and fully complies with high quality standards. Be 
            careful: every properly prepared drink has a deep taste and dizzying aroma, which can be addictive :D
            <br/>
            <br/>
            Our mission is to bring the right, and most importantly, high-quality tea to every home. That is why we carefully monitor that our prices are always 
            favorable and affordable - the store has a flexible system of discounts and gifts for orders.
            <br/>
            <br/>
            Tea plantation couriers are the friendliest and fastest couriers in all of Belarus. If the order is placed before 14:00, we will deliver your favorite tea 
            and any other goods right on the day of the order! If the order is formed after 14:00, the courier will arrive the next day.
            <br/>
            <br/>
            We are for every person on Earth to try real, right tea. Are you not from Minsk? No problem! We will deliver your order throughout Belarus by Belpochta or a 
            transport company. Are you in another country, but really want to buy tea from our online store? Do not worry! We will find a way to deliver your order to 
            you! We work with all transport companies in the world :D
            <br/>
            <br/>
            The tea plantation guarantees that payment for the order will be convenient and easy for you. Pay as you wish: in cash, by card online, upon receipt, 
            during self-delivery - as it will be convenient for you!
            <br/>
            <br/>
            The more tea the better! We are always ready for wholesale orders and provide the most favorable conditions for wholesale in Minsk. Also, our employees will 
            be happy to help you in drawing up a tea card, train your staff and take over the production of corporate gifts! Delivery of small and large wholesale is 
            completely free to your warehouse or office.
            <br/>
            <br/>
            In the tea plantation, everything complies with the legislation of the Republic of Belarus - we have all quality certificates and declarations of conformity 
            with the Customs Union. You can get acquainted with them at any time in our cozy shop at Minsk, Umanskaya street, 54.
            <br/>
            <br/>
            Can't make a choice? Come to our shop for a free tasting of various varieties of tea and coffee. So you can buy exactly what you like, and you will enjoy 
            your favorite drink after purchase!
            <br/>
            <br/>
            Each of our clients becomes our friend. You can ask this to thousands of satisfied customers! We sincerely hope and believe that we will also be able to 
            build long-term friendly relations with you. Rather, go on an exciting journey through our online catalog, select the desired categories and discover new 
            tastes. See you in Minsk ;D
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
export default About;