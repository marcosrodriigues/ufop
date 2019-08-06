import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import * as CanvasJS from '../../../assets/js/canvasjs.min';


@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.css']
})
export class SearchComponent implements OnInit {

  cidade = '';

  data = [
    { y: 52, name: "Abertura para o novo" },
    { y: 68, name: "Realização" },
    { y: 40, name: "Extroversão" },
    { y: 35, name: "Socialização" },
    { y: 75, name: "Neuroticismo" },
  ];

  constructor(private router: ActivatedRoute) { 
    this.router.queryParams.subscribe(params => {
      this.cidade = params['q'];
    })
  }

  ngOnInit() {
      this.initializeChart('chart1');
      this.initializeChart('chart2');
      this.initializeChart('chart3');
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
        type: "pie",
        showInLegend: true,
        toolTipContent: "<b>{name}</b>: {y} (#percent%)",
        indexLabel: "{name} - #percent%",
        dataPoints: this.data,
      }]
    });
    chart.render();
  }

}
