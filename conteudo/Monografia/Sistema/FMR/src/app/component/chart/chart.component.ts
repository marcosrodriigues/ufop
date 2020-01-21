import { Component, OnInit, Input } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';

@Component({
  selector: 'app-chart',
  templateUrl: './chart.component.html',
  styleUrls: ['./chart.component.css']
})
export class ChartComponent implements OnInit {

  @Input("personality") personality: any = {};

  dataChart = [
    { y: 0.1, label: "Abertura" },
    { y: 0.1, label: "Concordância" },
    { y: 0.1, label: "Consciência" },
    { y: 0.1, label: "Extroversão" },
    { y: 0.1, label: "Neuroticismo" },
  ];

  constructor() { }

  ngOnInit() {
    this.configureMe();
    this.initializeChart('chart');
  }

  ngOnChanges() {
    this.configureMe();
    this.initializeChart('chart');
  }

  configureMe() {
    if (this.personality != null) {
        this.dataChart[0].y = this.round(this.personality.abertura / 50 * 100, 2);
        this.dataChart[1].y = this.round(this.personality.concordancia / 45 * 100, 2);
        this.dataChart[2].y = this.round(this.personality.consciencia / 45 * 100, 2);
        this.dataChart[3].y = this.round(this.personality.extroversao / 40 * 100, 2);
        this.dataChart[4].y = this.round(this.personality.neuroticismo / 40 * 100, 2);
    }
  }

  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      title:{
        text: "Personalidade"
      },
      axisY : {
        title: "Pontuação"
      },
      data: [{
        type: "column",
        toolTipContent: "<b>{label}</b>: {y}%",
        dataPoints: this.dataChart,
      }]
    });
    chart.render();
  }

  private round(value, exp) {
    return parseFloat(value.toFixed(exp));
  }
}