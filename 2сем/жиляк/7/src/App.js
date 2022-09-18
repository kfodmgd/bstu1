import React from 'react'

import Calendar from './components/calendar';

class App extends React.Component{
  state={
    date:null,
  };

  handleDateChange=date=>this.setState({date});

  render(){
    const {date}=this.state;
    return(
      <div>
        <Calendar  
        onChange={this.handleDateChange}
        />
       {date && <p>Выбранная дата: {date.toLocaleDateString()}</p>}
      </div>
    );
  }
}

export default App;
