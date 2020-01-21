import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-index',
  templateUrl: './index.component.html',
  styleUrls: ['./index.component.css']
})
export class IndexComponent implements OnInit {

  search = "";

  constructor(private _router: Router) { }

  ngOnInit() {
  }

  submit() {
    this._router.navigate(['search', this.search, 'TODOS']);
    //window.location.href = 'search?cidade=' + this.search + '&carater=TODOS';
  }
}
