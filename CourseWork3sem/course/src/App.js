import './App.css';

import {Main} from './Main';
import Assort from './Assort';
import Cart from './Cart';
import About from './AboutUs';

import {Routes,Route} from 'react-router-dom';

function App() {
  return (
    <div className="App">
      <Routes>
      <Route path='/' element={<Main/>}/>
      <Route path='/Assort' element={<Assort/>}/>
      <Route path='/Cart' element={<Cart/>}/>
      <Route path='/About' element={<About/>}/>
      </Routes>
    </div>
  );
}

export default App;
