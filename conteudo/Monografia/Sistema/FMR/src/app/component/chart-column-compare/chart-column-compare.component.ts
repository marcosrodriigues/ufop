import { Component, OnInit, Input } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';

@Component({
  selector: 'app-chart-column-compare',
  templateUrl: './chart-column-compare.component.html',
  styleUrls: ['./chart-column-compare.component.css']
})
export class ChartColumnCompareComponent implements OnInit {

  @Input("me") me: any = {};
  @Input("other") other: any = {};
  @Input("i") i: any = 0;

  myData: any = [
    { y: 0.1, label: "Abertura para o novo" },
    { y: 0.1, label: "Concordancia" },
    { y: 0.1, label: "Consciencia" },
    { y: 0.1, label: "Extroversao" },
    { y: 0.1, label: "Neuroticismo" }
  ];

  otherData: any = [
    { y: 0.1, label: "Abertura para o novo" },
    { y: 0.1, label: "Concordancia" },
    { y: 0.1, label: "Consciencia" },
    { y: 0.1, label: "Extroversao" },
    { y: 0.1, label: "Neuroticismo" },
  ]

  constructor() { }

  ngOnInit() {
    this.init();
  }

  ngOnChanges() {
    this.init();
  }

  init() {
    setTimeout(() => {
      this.configure();
      this.initializeChart("chart_" + this.i);
    })
  }

  configure() {
    this.myData[0].y = this.round(this.me.abertura / 50 * 100, 2);
    this.otherData[0].y = this.round(this.other.abertura / 50 * 100, 2);

    this.myData[1].y = this.round(this.me.concordancia / 45 * 100, 2);
    this.otherData[1].y = this.round(this.other.concordancia / 45 * 100, 2);

    this.myData[2].y = this.round(this.me.consciencia / 45 * 100, 2);
    this.otherData[2].y = this.round(this.other.consciencia / 45 * 100, 2);

    this.myData[3].y = this.round(this.me.extroversao / 40 * 100, 2);
    this.otherData[3].y = this.round(this.other.extroversao / 40 * 100, 2);

    this.myData[4].y = this.round(this.me.neuroticismo / 40 * 100, 2);
    this.otherData[4].y = this.round(this.other.neuroticismo / 40 * 100, 2);
  }


  private round(value, exp) {
    return parseFloat(value.toFixed(exp));
  }

  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      exportEnabled: true,
      title:{
        text: "República vs Estudante"
      },
      axisY: {
        title: "Pontuação"
      },
      toolTip: {
        shared: true
      },
      legend: {
        cursor: "pointer"
      },
      data: [{
        type: "column",
        name: "Minha personalidade",
        legendText: "Minha personalidade",
        showInLegend: true,
        dataPoints: this.myData,
      },{
        type: "column",
        name: "República",
        legendText: "Personalidade da República",
        showInLegend: true,
        dataPoints: this.otherData,
      },]
    });
    chart.render();
  }
}
