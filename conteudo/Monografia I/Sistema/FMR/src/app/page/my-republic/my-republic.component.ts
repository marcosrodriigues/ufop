import { Component, OnInit } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';

@Component({
  selector: 'app-my-republic',
  templateUrl: './my-republic.component.html',
  styleUrls: ['./my-republic.component.css']
})
export class MyRepublicComponent implements OnInit {

  rep = "República Maternidade";
  fullImagePath = '/content/republica/maternidade.png';

  data = [
    { y: 52, name: "Abertura para o novo" },
    { y: 68, name: "Realização" },
    { y: 40, name: "Extroversão" },
    { y: 35, name: "Socialização" },
    { y: 75, name: "Neuroticismo" },
  ];

  constructor() { 
  }

  ngOnInit() {
      this.initializeChart('chart');
  }

  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      exportEnabled: true,
      title:{
        text: "Personalidade"
      },
      data: [{
        type: "column",
        showInLegend: true,
        toolTipContent: "<b>{name}</b>: {y} (#percent%)",
        indexLabel: "{name} - #percent%",
        dataPoints: this.data,
      }]
    });
    chart.render();
  }

}
