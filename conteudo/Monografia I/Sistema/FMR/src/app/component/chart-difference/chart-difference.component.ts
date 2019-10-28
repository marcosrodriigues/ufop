import { Component, OnInit, Input } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';

@Component({
  selector: 'app-chart-difference',
  templateUrl: './chart-difference.component.html',
  styleUrls: ['./chart-difference.component.css']
})
export class ChartDifferenceComponent implements OnInit {

  @Input("me") me: any = {};
  @Input("other") other: any = {};
  @Input("i") i: any = 0;

  data: any = [
    { y: 0.1, label: "Abertura para o novo" },
    { y: 0.1, label: "Concordancia" },
    { y: 0.1, label: "Consciencia" },
    { y: 0.1, label: "Extroversao" },
    { y: 0.1, label: "Neuroticismo" }
  ];

  constructor() { }

  ngOnInit() {
    this.init();
  }

  ngOnChange() {
    this.init();
  }

  private init() {
    setTimeout(() => {
      this.configure();
      this.initializeChart("chartDiff_" + this.i);
    }, 500)
  }

  configure() {
    this.data[0].y = this.round(this.me.abertura / 50 * 100, 2) - this.round(this.other.abertura / 50 * 100, 2);
    this.data[1].y = this.round(this.me.concordancia / 45 * 100, 2) - this.round(this.other.concordancia / 45 * 100, 2);
    this.data[2].y = this.round(this.me.consciencia / 45 * 100, 2) - this.round(this.other.consciencia / 45 * 100, 2);
    this.data[3].y = this.round(this.me.extroversao / 40 * 100, 2) - this.round(this.other.extroversao / 40 * 100, 2);
    this.data[4].y = this.round(this.me.neuroticismo / 40 * 100, 2) - this.round(this.other.neuroticismo / 40 * 100, 2)
  }

  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      title:{
        text: "Diferença de personalidade"
      },
      axisY : {
        title: "Pontuação"
      },
      data: [{
        type: "column",
        toolTipContent: "<b>{label}</b>: {y}%",
        dataPoints: this.data,
      }]
    });
    chart.render();
  }

  private round(value, exp) {
    return parseFloat(value.toFixed(exp));
  }
}