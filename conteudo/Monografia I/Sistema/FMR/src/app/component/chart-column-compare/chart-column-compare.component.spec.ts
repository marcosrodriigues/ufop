import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ChartColumnCompareComponent } from './chart-column-compare.component';

describe('ChartColumnCompareComponent', () => {
  let component: ChartColumnCompareComponent;
  let fixture: ComponentFixture<ChartColumnCompareComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ChartColumnCompareComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ChartColumnCompareComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
