import React from 'react';

import './index.css';

import * as calendar from './calendar';
import classnames from 'classnames';

export default class Calendar extends React.Component{
    //статическое свойство определяется у класса а не у объекта
    static defaultProps={
        date:new Date(),//значение по умолчанию
        years:[2012,2013,2014,2015,2016,2017,2018,2019,2020,2021,2022,2023],
        monthNames:['Январь','Февраль','Март','Апрель','Май','Июнь','Июль','Август','Сентябрь','Октябрь','Ноябрь','Декабрь'],
        weekDayNames:['Пн','Вт','Ср','Чт','Пт','Сб','Вс'],
        onChange:Function.prototype,//вызов пустой функции, которая ничего не возвращает
    };

    state={
        date:this.props.date,
        currentDate:new Date(),//текущаая дата
        selectedDays:null,//выбранная дата
        //selectedDays: [],
        showForm: false,
        noteDate: new Date(),
        notes: [],
    };


//--------------------------------------------------------------------------------------
selectDays = (day) => {
  for (let i = 0; i < this.state.selectedDays.length; i++) {
    if (
      day.getDate() === this.state.selectedDays[i].getDate() &&
      day.getMonth() === this.state.selectedDays[i].getMonth() &&
      day.getFullYear() === this.state.selectedDays[i].getFullYear()
    )
      return this.setState({
        showForm: !this.state.showForm,
        noteDate: day,
      });
  }
  this.setState(({ selectedDays }) => ({
    selectedDays: [...selectedDays, day],
  }));
};

//--------------------------------------------------------------------------------------
    


    //чистка больших участков
    get year(){
        return this.state.date.getFullYear();
    }
    get month(){
        return this.state.date.getMonth();
    }
    get day(){
        return this.state.date.getDate();
    }

    //функции для обработки событий на кнопках
    handlePrevMonthButtonClick=()=>{
        const date=new Date(this.year,this.month-1);
        //console.log(date);
        this.setState({date});
    };

    handleNextMonthButtonClick=()=>{
        const date=new Date(this.year,this.month+1);
        //console.log(date);
        this.setState({date});
    };
    
    handleSelectChange=()=>{
        const year=this.yearSelect.value;//получение значения года их соотв селекта
        const month=this.monthSelect.value;
        const date=new Date(year,month);
        //console.log(date);
        this.setState({date});
    };//обработка 2 селектов

    handleDayClick= date =>{
        console.log(date);
        this.setState({selectedDays:date});//установка состояния

        this.props.onChange(date);//передача выбранного состояния



        //---------------------------------------------------------------------
        return this.setState({
            showForm: !this.state.showForm,
            noteDate: date,
          });
    };



    render(){
        const {years, monthNames, weekDayNames}=this.props;//получение доступа из объектов класса
        const {currentDate, selectedDays}=this.state;
        //само заполнение календаря датами
        const monthData=calendar.getMonthData(this.year, this.month);

        return(
            <div className="calendar">
                <header>
                    <button onClick={this.handlePrevMonthButtonClick}>{'<'}</button>
                    <select
                    ref={element=>this.monthSelect=element}//для получения доступа к дом элементам
                    value={this.month}
                    onChange={this.handleSelectChange}>
                    {monthNames.map((name,index)=>
                        <option key={name} value={index}>{name}</option>
                    )}
                    </select>
                    <select 
                    ref={element=>this.yearSelect=element}
                    value={this.year}
                    onChange={this.handleSelectChange}>
                    {years.map(year=>
                        <option key={year} value={year}>{year}</option>
                    )}
                    </select>
                    <button onClick={this.handleNextMonthButtonClick}>{'>'}</button>
                </header>

                <table>
                    <thead>
                        <tr>
                            {weekDayNames.map((name)=>
                                <th key={name} value={name}>{name}</th>
                            )}
                        </tr>
                    </thead>

                    <tbody>
                        {monthData.map((week,index)=>//перебор всех строк в monthData
                        
                        <tr key={index} className="week">
                            
                            {week.map((date,index)=>//перебор всех элементов в массиве объекта monthData
                                date ? 
                                <td key={index} className={classnames('day',{
                                    "today" : calendar.areEqual(date,currentDate),
                                    "selected":calendar.areEqual(date,selectedDays),
                                })}
                                onClick={()=>this.handleDayClick(date)}/*ссылка на стрелочную функцию чтобы нам в консоле передавалась сама date*/>
                                    {date.getDate()}
                                </td>
                                :
                                <td key={index}/>//Выбор чем заполняем:если есть, то заполняем с помощью метода getDate()
                            )}
                        </tr>
                    )}
                    </tbody>
                </table>
            </div>
        );
    }
}